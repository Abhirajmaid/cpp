/*
 a) The internship is offered to students based on rank obtained in second year of graduation. Create 
suitable non-linear data structure to identify next topper student for internship. (Create max-heap).
b) Sort the student data in ascending order of grades
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
void max_heapify(int *a,int i,int n){
    int largest=i;
    int left=2*i+ 1;
    int right=2*i+ 2;
    if(left<n && a[left]>a[largest]) largest=left;
    if(right<n && a[right]>a[largest]) largest=right;
    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(a,largest,n);
    }
}
void build_maxheap(int *a,int n){
    int i;
    for(i=(n/2)-1;i>=0;i--){
        max_heapify(a,i,n);
    }
}
void heapsort(int *a,int n){
    int i,temp;
    for(i=(n/2)-1;i>=0;i--){
        max_heapify(a,i,n);
    }
    for(i=n-1;i>=0;i--){
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        max_heapify(a,0,i);
    }
}
int maximum(int *a,int n){
    int max = a[0];
    int l=n-1;
    a[0] = a[l];
    l = l-1;
    max_heapify(a, 0,l);
    return max;
}
int main(){
    int ch,n,a[30],k;
    do{
    cout<<"\nMenu\n1.Enter student grade obtained in second year of graduation"<<endl;
    cout<<"2.Selected student for internship"<<endl;
    cout<<"3.Ascending order by grade "<<endl;
    cout<<"4.Show max heap "<<endl;
    cout<<"0.Exit\nchoice : ";
    cin>>ch;
    switch(ch){
        case 1:
        cout<<"Enter no of students : ";
        cin>>n;
        cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<"grade of student "<<i<<" : ";
            cin>>a[i];
        }
        break;
        case 2:
        build_maxheap(a,n);
        k=maximum(a,n);
        cout<<"\nInternship offered to student with "<<k<<" Grades "<<endl;
        break;
        case 3:
        heapsort(a,n);
        cout<<"\nSorted output ( Ascending order ) :\n";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        break;
        case 4:
        build_maxheap(a,n);
        cout<<"\nMax heap : "<<endl;
        for(int i=0;i<n;i++){
            cout<<"\t"<<a[i];
        }
        break;
    }
    }
    while(ch!=0);
}

/*
Menu
1.Enter student grade obtained in second year of graduation
2.Selected student for internship
3.Ascending order by grade
4.Show max heap
0.Exit
choice : 1
Enter no of students : 7

grade of student 0 : 15
grade of student 1 : 25
grade of student 2 : 75
grade of student 3 : 5
grade of student 4 : 60
grade of student 5 : 50
grade of student 6 : 30

Menu
1.Enter student grade obtained in second year of graduation
2.Selected student for internship
3.Ascending order by grade
4.Show max heap
0.Exit
choice : 4

Max heap :
        75      60      50      5       25      15      30
Menu
1.Enter student grade obtained in second year of graduation
2.Selected student for internship
3.Ascending order by grade
4.Show max heap
0.Exit
choice : 3

Sorted output ( Ascending order ) :
5 15 25 30 50 60 75
Menu
1.Enter student grade obtained in second year of graduation
2.Selected student for internship
3.Ascending order by grade
4.Show max heap
0.Exit
choice : 2

Internship offered to student with 75 Grades

Menu
1.Enter student grade obtained in second year of graduation
2.Selected student for internship
3.Ascending order by grade
4.Show max heap
0.Exit
choice : 2

Internship offered to student with 60 Grades

Menu
1.Enter student grade obtained in second year of graduation
2.Selected student for internship
3.Ascending order by grade
4.Show max heap
0.Exit
choice :
*/
