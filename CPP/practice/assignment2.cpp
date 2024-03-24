#include "ArrayADT.cpp"

class ExtendedArray : public Array
{
    public:
        ExtendedArray(int);
        void sort();
        int greatest();
        int smallesst();
        int search(int);
        int sum();
        float average();
        void rotateRightByOne();
        void removeDuplicate();
        int secondLargest();
        void swapItem(int,int);
};
void ExtendedArray :: swapItem(int i, int j)
{
    int temp;
    if(i>=0 && i<count() && j<count() && j>=0)
    {
        temp = get(i);
        edit(i,get(j));
        edit(j,temp);
    }
}
int ExtendedArray :: secondLargest()
{
    int r,i,temp;
    if(count()>=2)
        for(r=1; r<=count()-1; r++)
            for(i=0; i<=count()-1-r; i++)
                if(get(i) > get(i+1))
                {
                    temp = get(i);
                    edit(i, get(i+1));
                    edit(i+1,temp);
                }
        return count()-2;
}
void ExtendedArray :: removeDuplicate()
{
    for(int i=0; i<count(); i++)
    {
        for(int j=i+1; j<count(); j++)
        {
            if(get(i) == get(j))
            {
               del(j);
                j--;
            }
        }
    }
}
void ExtendedArray :: rotateRightByOne()
{
    int temp;
    int lastIndex;
    if(!isEmpty())
    {
        lastIndex = count()-1;
        temp = get(lastIndex-1);
        for(int i=lastIndex; i>0; i++)
            edit(i, get(i-1));
        edit(0, temp);
    }
}
float ExtendedArray :: average()
{
    return (float)sum()/count();
}
int ExtendedArray :: sum()
{
    if(isEmpty())
    {
        cout<<endl<<"Array id Empty";
        return -1;
    }
     int s=0;
    for(int i=0; i<count(); i++)
    {
        s=s+get(i);
    }
      return s;
}
int ExtendedArray :: search(int data)
{
    if(isEmpty())
    {
        cout<<endl <<"Array is Empty";
        return -1;
    }
    for(int i=0; i<count(); i++)
    {
        if(get(i)==data)
            return i;
    }
     return -1;
}
int ExtendedArray :: smallesst()
{
    int min;
    if(isEmpty())
    {
        cout<<endl<<"Array is empty";
    }
        min = get(0);
    for(int i=0; i<count(); i++)
        if(min > get(i))
            min = get(i);
        return min;
}
int ExtendedArray :: greatest(){
    int max;
    if(isEmpty()){
        cout<<endl<<"Array is Empty";
        return -1;
    }
    max=get(0);
    for(int i=1; i<count(); i++)
        if(max<get(i))
            max=get(i);
        return max;
}
ExtendedArray :: ExtendedArray(int cap):Array(cap)
{

}
void ExtendedArray :: sort()
{
    for(int r=1; r<=count()-1; r++)
    {
        for(int i=0; i<=count()-1-r; i++)
        {
            if(get(i) > get(i+1))
            {
                int temp = get(i);
                edit(i,get(i+1));
                edit(i+1,temp);
            }
        }
    }
}
