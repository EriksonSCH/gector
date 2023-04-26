#include <iostream>
#include <memory.h>
#include <vector>

template<typename T>
class gector{};

template<>
class gector<int>{
private:
	int* arr;
	int ssize;
	int index;
public:
	gector(uint32_t size){
		arr = new int[size];
		ssize = size;
		index = 0;
	}
	~gector(){
		delete[] arr;
	}
	void push_back(uint32_t elem){
		arr[index++] = elem;
	}
	void pop_back(){
		int i, count = 0;
		for(i = index; arr[i] == 0; i--){
			count++;
		}
		memset(arr + index - count, 0, sizeof(int));
	}
	int size(){
		return ssize;
	}
	int operator[](int index){
		if(index > this->index){
			return -1;
		}
		else{
			return arr[index++];
		}
	}
};

int main(int argc, char* argv[]){
	/* Example */
	gector<int> gec(3);
	gec.push_back(12);
	std::cout << gec[0] << std::endl;
	gec.pop_back();
}
