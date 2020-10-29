#include<iostream>

int main()
{
    int hour=0;
    int minute=0;
    int seconds=0;
    
    std::cout << "Enter Hour:";
    std::cin >> hour;
    //std::cout <<std::endl;

    std::cout << "Enter Minute:";
    std::cin >> minute;
  //  std::cout << std::endl;

    std::cout << "Enter Seconds:";
    std::cin >> seconds;
    std::cout << std::endl;
     //   std::cout <<" Can not be converted" << std::endl;
        
    std::cout <<"Your Entered Data is " << hour <<" hours "<<minute<<" minutes " <<seconds<<" seconds"<<std::endl;

    int cal_second = seconds + 60*minute + 60*hour*60;
    

    std::cout << std::endl <<"Converted Time in Seconds: " << cal_second << " seconds" << std::endl;

    
    return 0;

}
