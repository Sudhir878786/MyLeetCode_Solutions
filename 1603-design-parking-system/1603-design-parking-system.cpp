class ParkingSystem {
public:
    vector<int>ans;
    ParkingSystem(int big, int medium, int small) {
        ans={big,medium,small};
    }
    
    bool addCar(int carType) {
   
        int a=ans[carType-1]--;
        
        if(a>0){
            
            return 1;
        }return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */