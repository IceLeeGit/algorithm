#include <iostream>
#include <stdlib.h>
#define Max 64

using namespace std;


struct stack_t{
    int len;
    int data[Max];
    char name;
    void push(int num)
    {
        data[++len] = num;
    }
    int pop()
    {
        return data[len--];
    }
    int get()
    {
        if(len>=0)
            return data[len];
        else
            return -1;
    }
};

void transfer_tower(int num); 

int main(int argc,char** argv)
{
    stack_t tower;
    tower.len=-1;
    tower.push(1);
    tower.push(2);
    //cout<<tower.get()<<endl;
    int num;
    if (argc>1)
        num = atoi(argv[1]);
    else
        cin>>num;
    transfer_tower(num);
    return 0;

}

void transfer_tower(int num)
{
    int step=1;
    stack_t tower[3];
    tower[0].len = -1;
    tower[0].name='A';
    for (int i=0;i<num;i++)
    {
        tower[0].push(num-i);
    }
    tower[1].len = tower[2].len = -1;
    tower[1].name = 'B';
    tower[2].name = 'C';

    int iter,forward,mid,back;
    iter = forward = mid = back =0;
    int x;
    if (num%2==0)
        x=0;
    else
        x=1;

    while (tower[2].len != num-1 )
    {
        forward = (iter+2-x)%3;
        mid = iter%3;
        back = (iter+1+x)%3;

        //cout<<"iter: "<<iter<<" forward: "<<forward<<" mid: "<<mid<<" back: "<<back<<endl;;

        if (tower[mid].len !=-1)
        {
            if(tower[back].len==-1 || tower[back].get()>tower[mid].get())
            {
                tower[back].push(tower[mid].pop());
                cout<<step<<" Move: " <<tower[mid].name<<" ---> "<<tower[back].name<<endl;
                step++;
            }
            //cout<< tower[forward].name <<"  "<<tower[forward].get()<<endl;
            //cout<< tower[mid].name <<"  "<<tower[mid].get()<<endl;
            if ( tower[mid].len ==-1 )
            {
                if (tower[forward].len != -1)
                {
                    tower[mid].push(tower[forward].pop());
                    cout<<step<<" Move: " <<tower[forward].name<<" ---> "<<tower[mid].name<<endl;
                    step++;
                }
            }
            else if(tower[forward].len==-1 || tower[forward].get()>tower[mid].get())
            {
                tower[forward].push(tower[mid].pop());
                cout<<step<<" Move: " <<tower[mid].name<<" ---> "<<tower[forward].name<<endl;
                step++;
            }
            else if (tower[forward].get()<tower[mid].get())
            {
                tower[mid].push(tower[forward].pop());
                cout<<step<<" Move: " <<tower[forward].name<<" ---> "<<tower[mid].name<<endl;
                step++;

            }
        }
        iter=iter+x+1;
    }
}
