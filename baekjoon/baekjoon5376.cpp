#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string str;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        
        auto idx = str.find('(');
        int nlength = 0;
        int ilength = 0;
        string dm = "";
        string m = "";
        long long im = 0;
        long long idm = 0;
        
        if(idx != string::npos)
        {
            nlength = (int)idx - 2;
            ilength = (int)str.length() - (int)(idx + 2);
            
            m = str.substr(2, nlength) + str.substr(idx + 1, ilength);
            
            for(int j = 0; j < ilength; j++)
                dm += '9';
            for(int j = 0; j < nlength; j++)
                dm += '0';
            
            if(nlength)
                im = stoll(m) - stoll(str.substr(2, nlength));
            else
                im = stoll(m);
            idm = stoll(dm);
                
        }
        else
        {
            nlength = (int)str.length() - 2;
            
            m = str.substr(2, nlength);
            
            dm += '1';
            for(int j = 0; j < nlength; j++)
                dm += '0';
            
            im = stoll(m);
            idm = stoll(dm);
        }
        

        long long gcd = 0;
        long long _im = im;
        long long _idm = idm;
        
        while(1)
        {
            long long r = _idm % _im;
            
            if(r == 0)
            {
                gcd = _im;
                break;
            }
            
            _idm = _im;
            _im = r;
        }
        
        cout << im / gcd << '/' << idm / gcd << '\n';
            
    }
}
