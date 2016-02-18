/*
	Develop an implementation of a load balancer for incoming IP traffic.  
		Assume the input is 32-bit integer.  The load balancer must 
		distribute load among 5 servers.  Write a simple algorithm that 
		implements load balancing between 5 servers WITHOUT explicitly 
		using stack or heap memory.  (The answer should only be a few lines 
		of code).
 */

/*
	use it as:
		loadBalancer myLoadBalancer;
		int server = myLoadBalancer(IP);
 */
class loadBalancer
{
public:
	/**
      @param IP: an int
      @return: An int denotes one of the 5 servers, ranging from 1 to 5.
     */
	int operator()(int IP)
	{
		return IP % 5 + 1;
	}
};
