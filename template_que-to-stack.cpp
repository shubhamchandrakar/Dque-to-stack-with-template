#include<iostream>
#include<string.h>
using namespace std;
template<class T > class queue;		// queue class declaration
template<class T > class _stack;	// _stack class declaration
template<class T > void stack_functionality(T);		//Function for performing stack functionality
template<class T > void queue_functionality(T);		//Function for performing stack functionality
// queue class defination
template<class T>
class queue{
	T *q;
   int size, f, r;
public:
	queue()
	{
		q=NULL;
		size=0;
		f=r= -1;
		// std::cout << "queue constructor" << '\n';
	}
	~queue()
	{
		delete q;
//		cout<<"in delete = "<<s;
		size=0;
		f = r = -1;
		// std::cout << "queue destructor" << '\n';
	}

//Assigning size of queue
	void get_size(int n){
		q= new T[n];
		size= n;
		// cout << "queue get_size" << '\n';
	}
	void Enque(T);
	T Dque();
	bool under_flow();
	bool over_flow();
	void display();
	void insert_front(T);
	T delete_last();
	T peap_last();
};



// for checking underflow
template<class T> bool queue<T>::under_flow(){
	return((f==-1)&&(r==-1));
}

// for checking overflow
template<class T> bool queue<T>::over_flow(){
	return(f== (r+1)%size);
}

// Delete from front
template<class T> T queue<T>::Dque(){
	T x =-99;
	if(!under_flow()){
			x= q[f];
			if (f==r) {
					f=r=-1;
			}else{
					// f++;
					f= (f+1)%size;
			}
	}else{
			cout<< "\n=========================== Queue is under flow ===========================\n";
	}
	return x;
}

// Delete from rear
template<class T> T queue<T>::delete_last(){
	T x =-99;
	if(!under_flow()){
			x= q[r];
			if (f==r) {
				f=r= -1;
			}
			if (r==0) {
					r=size-1;
			}else if(r>0){
					r--;
			}
	}else{
			cout<< "\n=========================== Queue is under flow ===========================\n";
	}
	return x;
}
// Peap function for stack
template<class T> T queue<T>::peap_last(){
	T x =-99;
	if(!under_flow()){
			x= q[r];
	}else{
		cout<< "\n=========================== Queue is under flow ===========================\n";
	}
	return x;
}

// Insert from rear
template<class T> void queue<T>::Enque(T ele){
	if (!over_flow()) {

			if (r==-1&& f== -1) {
				f = (f+1)%size;
			}
				r= (r+1)%size;
				q[r] = ele;

	} else {
		cout<< "\n=========================== Queue is over flow ===========================\n";
	}
}

// Insert from front
template<class T> void queue<T>::insert_front(T ele){
	if (!over_flow()) {
			if(f== 0){
				f = size;
			}
			if (r==-1&& f== -1) {
				f++;
				r++;
				q[f]= ele;
			}else{
				q[--f] = ele;
			}
	}else {
		cout<< "\n=========================== Queue is over flow ===========================\n";
	}
}

// Display function for queue
template<class T> void queue<T>::display(){
	if (!under_flow()) {
			int i;
			int tmp_r = r;
			cout<<"\n============================= Display =============================\n";
			// std::cout << "\n r= "<< r << '\n';
			// std::cout << "\n f= "<< f << '\n';
			if (r<f)
			{
				for(i=f;i!=r;){
					if (i < size) {
							cout<<" | "<<q[i];
							i++;
					}
					else{
						i=0;
					}
				}
				cout<<" | "<<q[i];
			}else{
				for(i=f;i<=r;i++){
					cout<<" | "<<q[i];
				}
			}

	} else {
		cout<< "\n=========================== queue is empty ===========================\n";
	}

}

// _stack class defination
template<class T>
class _stack:public queue<T>
{
public:
	_stack(){
		// std::cout << "stack constructor" << '\n';
	}
	~_stack(){
		// std::cout << "stack destructor" << '\n';
	}

	//push function for stack
	void push(T ele){
		if (!queue<T>::over_flow()) {
			queue<T>::Enque(ele);
			cout << "\n Element pushed in stack : "<< ele << '\n';
		}else{
			cout<<"\n====================== Stack is overflow ======================";
		}
	}

//pop function for stack
	T pop(){
		T x = -999;
		if (!queue<T>::under_flow()) {
			x = queue<T>::delete_last();
		}else{
			cout<<"\n====================== Stack is underflow ======================";
		}
		return x;
	}

//peap function for stack
	T peap(){
		T x = -999;
		if (!queue<T>::under_flow()) {
			x = queue<T>::peap_last();
		}else{
			cout<<"\n====================== Stack is underflow ======================";
		}
		return x;
	}
//display function for stack
	void stack_display(){
		if (!queue<T>::under_flow()) {
			cout << "\n Stack Elements : " << '\n';
			queue<T>::display();
		}else{
			cout<<"\n====================== Stack is Empty ======================";
		}

	}

//Assigning size of stack
	void get_size(int n){
		// cout<<"\n from stack size : "<<n;
		queue<T>::get_size(n);
	}


};
int main(){
		queue<int> q1;
		_stack<int> s1;
		int ch;
		cout << "\n 1: For stack " << '\n';
		cout << " 2: For Queue " << '\n';
		cin>>ch;
		if (ch == 1) {
			stack_functionality(s1); // stack_functionality function calling
		}else if(ch ==2){
			queue_functionality(q1); // queue_functionality function calling
		}else{
			cout<<"\nPlease select correct option";
		}


	return(0);
}

// all stack functionality
template<class T >
void stack_functionality(T s1) {
			int n,sw;
			int tmp, flag =0 ;
			cout<<"Enter the stack size : ";
			cin>>n;
			s1.get_size(n);
			while(flag == 0){
			cout << "\n================================================================== " << '\n';
			cout << "\nPlease select your choice" << '\n';
			cout << "\n 1: For push element in stack " << '\n';
			cout << " 2: For pop element in stack " << '\n';
			cout << " 3: For peap element in stack " << '\n';
			cout << " 4: For print elements of stack " << '\n';
			cout << " 5: Exit " << '\n';

			cin>>sw;
			switch(sw){
				case 1:
							//push into stack`
							if (!s1.over_flow()) {
								cout<<"Enter element : ";
								cin>> tmp;
								s1.push(tmp);
							}else{
								cout<<"\n====================== Stack is overflow ======================";
							}
							break;

				case 2:
							// pop from stack
							if (!s1.under_flow()) {
								cout<<"Poped element : "<<s1.pop();
							}else{
								cout<<"\n====================== Stack is Empty ======================";
							}
							break;
				case 3:
							// Peap from stack
							if (!s1.under_flow()) {
								cout<<"Peaped element : "<<s1.peap();
							}else{
								cout<<"\n====================== Stack is Empty ======================";
							}
							break;
				case 4:
							// display stack elements
							s1.stack_display();
							break;
				case 5:
							// Exit Condition
							flag = 1;
							break;
				default:
						break;
			}
		}
}

// all queue functionality
template<class T > void queue_functionality(T q1) {
			int n,sw;
			int tmp, flag =0 ;
			cout<<"Enter the queue size : ";
			cin>>n;
			q1.get_size(n);
			while(flag == 0){
			cout << "\n================================================================== " << '\n';
			cout << "\nPlease select your choice" << '\n';
			cout << "\n 1: Insert from rear in queue " << '\n';
			cout << " 2: Insert from front in queue " << '\n';
			cout << " 3: Delete from front in queue " << '\n';
			cout << " 4: Delete from rear in queue " << '\n';
			cout << " 5: Print queue " << '\n';
			cout << " 6: Exit " << '\n';

			cin>>sw;
			switch(sw){
				case 1:
							// insert into queue from rear
							cout<<"Enter element for inserting element from rear: ";
							cin>> tmp;
							q1.Enque(tmp);
							break;
				case 2:
							// insert into queue from front
							cout<<"Enter element for inserting element from front: ";
							cin>> tmp;
							q1.insert_front(tmp);
							break;
				case 3:
							// // Delete into queue from front
							if (!q1.under_flow()) {
									cout<<"Deleted element from front: "<<q1.Dque();
							}else{
								cout<< "\n=========================== queue is empty ===========================\n";
							}

							break;
				case 4:
							// Delete into queue from rear
							if (!q1.under_flow()) {
								cout<<"Deleted element from rear: "<<q1.delete_last();
							}else{
								cout<< "\n=========================== queue is empty ===========================\n";
							}
							break;
				case 5:
							// Display queue elements
							q1.display();
							break;
				case 6:
							// Exit Condition
							flag = 1;
							break;
				default:
							break;
			}
		}
}
