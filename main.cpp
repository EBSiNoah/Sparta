#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

double cal_Tot(vector<double> input)
{
	int idx=0;
	double sum=0;
	
	while(idx<input.size())
	{
		sum+=input[idx];
		idx++;
	}
	
	return sum;
}

double cal_Ave(vector<double> input)
{
	double sum=cal_Tot(input);
	
	return sum/input.size();
}

vector<double> upSort(vector<double> before)
{
	int idx=0;
	int sp=0;
	int ep=0;
	int mid=0;
	vector<double> after;

	after.push_back(before[0]);
	
	for(idx=1;idx<before.size();++idx)
	{
		sp=0;
		ep=after.size()-1;
		
		while(sp<=ep)
		{
			mid=(sp+ep)/2;
			if(before[idx]>after[mid])
			{
				sp=mid+1;
			}
			else if(before[idx]<after[mid])
			{
				ep=mid-1;
			}
			else
			{
				break;
			}
		}
		if(sp>ep)
		{
			mid=sp;
		}
		after.insert(after.begin()+mid,before[idx]);
	}
	return after;
}

vector<double> downSort(vector<double> before)
{
	int idx=0;
	int sp=0;
	int ep=0;
	int mid=0;
	vector<double> after;

	after.push_back(before[0]);
	
	for(idx=1;idx<before.size();++idx)
	{
		sp=0;
		ep=after.size()-1;
		
		while(sp<=ep)
		{
			mid=(sp+ep)/2;
			if(before[idx]>after[mid])
			{
				ep=mid-1;
			}
			else if(before[idx]<after[mid])
			{
				sp=mid+1;
			}
			else
			{
				break;
			}
		}
		if(sp>ep)
		{
			mid=sp;
		}
		after.insert(after.begin()+mid,before[idx]);
	}
	return after;
}

void print_Arr(vector<double> input)
{
	int idx=0;
	
	cout<<"current Array : ";
	
	while(idx<input.size())
	{
		cout<<input[idx]<<" | ";
		idx++;
	}
	cout<<endl;	
}

vector<double> convert(string input)
{
	vector<double> vec(2,0);
	double result=0;
	int idx=0;
	int dec=0;
	int dotcnt=0;
	bool isminus=0;
	
	while(idx<input.length())
	{
		dec++;
		if(input[idx] == 45 && idx == 0)
		{
			isminus=1;
		}
		else if(input[idx]>=48 && input[idx]<=57)
		{
			result+=result*10 + input[idx]-48;
		}
		else if(input[idx]==46 && dotcnt<1)
		{
			dotcnt++;
			dec=0;
		}
		else
		{
			vec[0]=1;
			break;
		}
		idx++;
	}
	
	idx=0;
	while(idx<dec && dotcnt>0)
	{
		result/=10;
		idx++;
	}
	
	if(isminus)
	{
		result*=-1;
	}
	
	vec[1]=result;
	
	return vec;
}

void key_Input()
{
	string key="";
	string number="";
	vector<double> vec;
	vector<double> isdouble;
	
	while(key!="Q" || key!="q")
	{
		cout<<"(I) is input element, (U) is up sort, (D) is down sort, (A) is average, (T) is total, (Q) is quit"<<endl;
		cout<<"command : ";
		cin>>key;
		if(key == "Q" || key == "q")
		{
			cout<<"quit"<<endl;
			break;
		}
		else if(key == "I" || key == "i")
		{
			cout<<"input : ";
			cin>>number;
			//vec.push_back(number);
			isdouble = convert(number);
			if(isdouble[0]==1)
			{
				cout<<"wrong input"<<endl;
			}
			else
			{
				vec.push_back(isdouble[1]);
			}
		}
		else if(key == "U" || key == "u")
		{
			cout<<"up sort : "<<endl;
			vec=upSort(vec);
		}
		else if(key == "D" || key == "d")
		{
			cout<<"down sort : "<<endl;
			vec=downSort(vec);
		}
		else if(key == "A" || key == "a")
		{
			cout<<"average : "<<cal_Ave(vec)<<endl;
		}
		else if(key == "T" || key == "t")
		{
			cout<<"total : "<<cal_Tot(vec)<<endl;
		}
		else
		{
			cout<<"wrong key : "<<key<<endl;
		}
		print_Arr(vec);
	}
}

int main() 
{
	key_Input();
	
	return 0;
}
