#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

void sortByID(Student* s, int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(s[j].id > s[j+1].id)
                swap(s[j], s[j+1]);
}

int binarySearch(Student* s, int n, int key) {
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(s[m].id==key) return m;
        else if(s[m].id<key) l=m+1;
        else h=m-1;
    }
    return -1;
}

int main() {
    int n=5, key;
    Student* s=new Student[n];
    
    cout<<"Enter 5 student records:\n";
    for(int i=0;i<n;i++){
        cout<<"\nEnter ID: ";
        cin>>s[i].id;
        cout<<"Enter Name: ";
        cin>>s[i].name;
        cout<<"Enter CGPA: ";
        cin>>s[i].cgpa;
    }

    sortByID(s,n);
    cout<<"\nAll Student Records (Sorted by ID):\n";
    for(int i=0;i<n;i++)
        cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].cgpa<<endl;

    cout<<"\nEnter ID to search: ";
    cin>>key;
    int pos=binarySearch(s,n,key);
    if(pos!=-1)
        cout<<"\nRecord Found:\n"<<s[pos].id<<"\t"<<s[pos].name<<"\t"<<s[pos].cgpa<<endl;
    else
        cout<<"\nRecord not found!\n";

    delete[] s;
    return 0;
}
