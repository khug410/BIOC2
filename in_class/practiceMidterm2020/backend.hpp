/*
* This code describes the backend of our application.
* It describes all operation of all of the underlying threads that run
 *behind the scences.
 
* @author Robert F Cooper <robert.cooper@marquette.edu>
* @version 1.3
*/
#include <boost/asio.hpp>

namespace Batch{
    namespace BackEnd{
        class ThreadPool{
			private:
				// @var size: The size of our threadPool.
				int size;
			public:
				// Constructor:
				// The constructor takes in the number of threads
				// and spawns them, relying on 
				ThreadPool(int numThreads);
			
				// GetPoolSize:
				// @return: the number of threads allowed in our pool.
				int getPoolSize();
        };
		
		/* BatchResult
		* DEPRECIATED
		*/
		class BatchResult{
		
		}
    }
}