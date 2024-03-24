#include "assignment-1.cpp"

class ExtendedArray : public Array
{
    public:
        ExtendedArray(int);
        void sort();
        int greatest();
        int smallest();
        int search(int);
        int sum();
        float average();
        void rotate();
        void removeDuplicate();
        int secondGreatest();
        void swapItems(int,int);

};
void ExtendedArray::swapItems(int i,int j)
{
    if(i>=0 && i<count() && j>=0 && j<count())
    {
        int temp=get(i);
        edit(i,get(j));
        edit(j,temp);
    }
}
int ExtendedArray::secondGreatest()
{
    if(count()>=2)
    {
        for(int r=1; r<=count()-1; r++)
        {
            for(int i=0; i<=count()-1-r; i++)
            {              
                if(get(i) > get(i+1))
                {
                    int temp=get(i);
                    edit(i,get(i+1));
                    edit(i+1,temp);
                }   
            }
        }
    }
    return get(count()-2);
    /*int large = greatest();
    int secondMax=-1;
    int min=get(0);
    for(int i=1; i<count(); i++)
    {
        if(secondMax<min && min < large)
        {
            secondMax = min;
        }
            min = get(i);
    }
    return secondMax;*/
}
void ExtendedArray::removeDuplicate()
{
    for(int i=0; i<count(); i++)
    {
        for(int j=i+1; j<count(); j++)
        {
            if(get(i)==get(j))
            {
                del(j);
                j--;
            }
        }
    }
}
void ExtendedArray::rotate()
{
    if(!isEmpty())
    {
        int temp=get(count()-1);
        for(int i=count()-1; i>0; i--)
        {
            edit(i,get(i-1));
        }
        edit(0,temp);
    }
}
float ExtendedArray::average()
{
    return (float)sum()/count();
}
int ExtendedArray::sum()
{
    int sum=0;
    for(int i=0; i<count(); i++)
    {
        sum+=get(i);
    }
    return sum;
}
int ExtendedArray::search(int data)
{
    for(int i=0; i<count(); i++)
    {
        if(get(i)==data)
        {
            return i;
        }
    }return -1;
}
int ExtendedArray::smallest()
{
    if(isEmpty())
    {
        cout<<"Array is Empty:)\n";
        return -1;
    }
    int min=get(0);
    for (int i = 0; i < count(); i++)
    {
        if(min>get(i))
        {
            min=get(i);
        }
    }
    return min;    
}
int ExtendedArray::greatest()
{
    if(isEmpty())
    {
        cout<<"Array is Empty:) \n";
        return -1;
    }
    int max=get(0);
    for(int i=1; i<count(); i++)
    {
        if(max<get(i))
        {
            max=get(i);
        }
    }
    return max;
}
void ExtendedArray::sort()
{
    for (int r = 1; r <= count()-1; r++)
    {
        for (int i = 0; i <= count()-1-r; i++)
        {
            int temp;
            if(get(i) > get(i+1))
            {
                temp=get(i);
                edit(i,get(i+1));
                edit(i+1,temp);
            }
        }        
    }    
}
ExtendedArray::ExtendedArray(int cap):Array(cap)
{

}

int main()
{
    ExtendedArray obj(5);

    // if(obj.isEmpty())
    //     cout<<"Array is Empty :) \n";

    obj.append(20);
    obj.append(80);
    obj.append(20);
    obj.append(90);
    obj.append(100);

    //obj.insert(3,80);
    //obj.edit(1,10);
    //obj.del(1);
    
    // if(obj.isFull())
    //     cout<<"Array is Full :) ";

    // cout<<obj.get(2)<<" ";

    // cout<<obj.count()<<" ";

    // cout<<obj.find(20)<<" ";

    //obj.sort();

    //obj.showData();

    //cout<<obj.greatest();

    //cout<<obj.smallest();

    //cout<<obj.search(30);

    //cout<<obj.sum();

    //cout<<"Average is: "<<obj.average();

    //obj.rotate();

    //obj.removeDuplicate();
    //obj.showData();

    //cout<<obj.secondGreatest();

    obj.swapItems(1,4);
    obj.showData();
    return 0;
}