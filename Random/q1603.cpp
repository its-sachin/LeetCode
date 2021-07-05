#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class ParkingSystem {
private:
    int b,m,s;
public:
    ParkingSystem(int big, int medium, int small) {
        b=big,m=medium,s=small;
    }
    
    bool addCar(int carType) {
        switch (carType)
        {
        case 1:
            if(b==0)
                return false;
            b-=1;
            break;
        
        case 2:
            if(m==0)
                return false;
            m-=1;
            break;
        
        case 3:
            if(s==0)
                return false;
            s-=1;
            break;
        
        default:
            return false;
            break;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main(int argc, char const *argv[])
{
    return 0;
}