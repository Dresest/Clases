#include <CL/sycl.hpp>
constexpr int N=16;
using namespace sycl;
int main(){
    queue q;
    std::vector<int> v(N);	
    buffer buff(v);
    q.submit([&](handler& h){
        accessor a(buff, h, write_only);
        h.parallel_for(N,[=](auto i) {
            a[i] = i;
        });
    }).wait();
    for (int i=0; i<N; i++) 
		std::cout << v[i] << "\n";
	return 0;
}
