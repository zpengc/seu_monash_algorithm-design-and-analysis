#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string str;
    getline(cin, str);
    for(int i=0;i<n;i++)
    {
        getline(cin, str);
        int num=0;
        for(int j=0;j<str.size();j++)
        {
            if(str[j]>='0' && str[j]<='9')
            {
                num++;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}