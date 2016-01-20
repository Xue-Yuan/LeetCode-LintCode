#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "cs402.h"
#include "my402list.h"
#include "transaction.h"
/*
    BUG:
        1. ?,???,???.?? won't show up.
*/
const int TenM = 10000000;
/********************************************************/
static
void malformedCmd()
{
    fprintf(stderr, "malformed command\n");
    exit(1);
}

static
int ProcessOptions(int argc, char *argv[])
{
    int reading_from_file = 0;

    if (argc < 2 || strcmp(argv[1], "sort") != 0) malformedCmd();
    if (argc > 2) reading_from_file = 1;
    return reading_from_file;
}

static void output(My402List*);

//Process the input and save it to Transaction object, then like it
//  to the list.
static
void Process(FILE *fp)
{
    char buf[1024];
    buf[1023] = '\0';

    My402List list;
    memset(&list, 0, sizeof(My402List));
    My402ListInit(&list);

    int at_least_one = 0;
    while(fgets(buf, sizeof(buf), fp) != NULL) 
    {
        at_least_one = 1;
        /* buf may contain '\n' */
        if (buf[1023] != '\n' && buf[1023] != '\0')
        {
            fprintf(stderr, "Error: Too long a line!\n");
            exit(1);
        }
        //Except the last line, lines end with "\n\0".
        if (buf[strlen(buf) - 1] == '\n') buf[strlen(buf) - 1] = '\0';
        //A new Transaction object
        Transaction *tran = (Transaction *)malloc(sizeof(Transaction));
        if (!tran)
        {
            fprintf(stderr, "Error: Malloc transaction object failed!\n");
            exit(1);
        }
        //save transaction to the list.
        if (!TransactionSet(tran, buf))
        {
            fprintf(stderr, "Error: Transaction initialisation failed!\n");
            exit(1);
        }
        My402ListAppend(&list, tran);
    }
    if (!at_least_one)
    {
        fprintf(stderr, "Error: There is no transaction!\n");
        exit(1);
    }
    //sort the transaction according to the timestamps
    list = TransactionMergeSort(&list);
    output(&list);
}

//generate output

/*
    +-----------------+--------------------------+----------------+----------------+
    |       Date      | Description              |         Amount |        Balance |
    +-----------------+--------------------------+----------------+----------------+
*/
void printHLine()
{
    int i = 0;
    for (i = 0; i < 80; ++i)
    {
        if (i == 0 || i == 18 || i == 45 || i == 62 || i == 79)
            printf("+");
        else printf("-");
    }
    printf("\n");
}

void printTitle()
{
    int i = 0;  
    char buffer[81];
    for (i = 0; i < 80; ++i)
    {
        // printf("%d", i % 10);
        buffer[i] = ' ';
    }
    // printf("\n");
    buffer[80] = '\0';
    strcpy(buffer + 8, "Date");
    strcpy(buffer + 20, "Description");
    strcpy(buffer + 55, "Amount");
    strcpy(buffer + 71, "Balance");
    buffer[12] = buffer[31] = buffer[61] = buffer[78] = ' ';
    buffer[0] = buffer[18] = buffer[45] = buffer[62] = buffer[79] = '|';
    printf("%s\n", buffer);
}

void amountGen(char *buffer, int tmp, int base)
{
    int idx = 0, cnt = 0;
    if (tmp / 100 >= TenM)
    {
        strcpy(buffer + base, "?,???,???.??");
        buffer[base + 12] = ' ';
    }
    else
    {
        buffer[base + 11] = (char)(tmp % 10 + '0');
        tmp /= 10;
        buffer[base + 10] = (char)(tmp % 10 + '0');
        tmp /= 10;
        idx = base + 8;
        while (tmp)
        {
            buffer[idx--] = (char)(tmp % 10 + '0');
            tmp /= 10;
            if (++cnt % 3 == 0 && tmp != 0) buffer[idx--] = ',';
        }
        while (idx >= base) buffer[idx--] = ' ';
    }
}

static
void output(My402List *list)
{
    //print the header
    printHLine();
    printTitle();
    printHLine();
    My402ListElem *elem = NULL;
    char buffer[81];
    buffer[80] = '\0';
    int i = 0;
    for (i = 0; i < 80; ++i) buffer[i] = ' ';
    buffer[0] = buffer[18] = buffer[45] = buffer[62] = buffer[79] = '|';
    buffer[57] = buffer[74] = '.';
    int balance = 0;
    for (elem = My402ListFirst(list); elem; elem = My402ListNext(list, elem))
    {
        Transaction *t = (Transaction *)elem->obj;
        time_t rawtime = (time_t)t->timestamp;
        struct tm *timeinfo = localtime (&rawtime);
        strftime (buffer + 2, 16, "%a %b %d %Y", timeinfo);
        buffer[17] = ' '; //get rid of the '\0'.
        //description
        strncpy(buffer + 20, t->description, 24);
        buffer[44] = ' '; //get rid of the '\0'.
        
        amountGen(buffer, (int)t->amount, 48);
        if (t->type == '-') 
        {
            buffer[47] = '('; buffer[60] = ')'; 
            balance -= (int)t->amount;
        }
        else balance += (int)t->amount;
        amountGen(buffer, balance, 65);
        if (balance < 0) {buffer[64] = '('; buffer[77] = ')';}

        printf("%s\n", buffer);
        printHLine();
    }
}
 
int main(int argc, char *argv[])
{
    int reading_from_file = ProcessOptions(argc, argv);

    if (reading_from_file) 
    {
        FILE *fp = fopen(argv[2], "r");
        if (fp == NULL) 
        {
            fprintf(stderr, "Error: Cannot open %s for reading.\n", argv[2]);
            return 0;
        }
        Process(fp);
        fclose(fp);
    } 
    else Process(stdin);

    return 0;
}
