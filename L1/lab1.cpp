    /**
     * @file lab1.cpp
     * @author Yogesh Mundhra
     * @Date   9/12/2017
     * @version 1.0
     * @section DESCRIPTION
     */
    // I declare that this assignment is my own work and that I have correctly
    // acknowledged the work of others.  I acknowledged that I have read and
    // following the Academic Honesty and Integrity related policies as
    // outlined in the syllabus.
    //
    // _____YOGESH MUNDHRA ____      _____16TH May 2018______________
    //
    // ____ 301346798 ______

    #include <iostream>
    #include <iomanip>

    using namespace std;

    // void calculateCost(int a, int b);

    int main()
    {
        // calculateCost(1,2);
        int startTime = 0;
        int callLength =0;
        int minutes = 0;
        double bill=0.00;
        char charone='\0';
        char chartwo='\0';
        char extra[256]={'\0'};
        bool weekday=false;
        bool weekend=false;
        bool validDay=false;
        char repeatchar='\0';
        bool repeat=false;

        do{                                                                     //do while loop for the entire program to repeat the whole program at the user's request
            do{
            cout << "Please enter the time call started in 24h format e.g. 16:20\n";
            cin >> startTime;
            cin.ignore();                                                       //ignores semi colon
            cin >> minutes;
            }while(startTime>24 || startTime<0 || minutes>=60 || minutes<0);    //checks whether time entered is within bounds

            do{                                                                 //do while to check for the characters entered for day
                cout << "Please enter the day of the week in the format Xy or XY or xY \n";
                cin >> charone >> chartwo;
                if((charone=='M' || charone=='m') && (chartwo=='o'||chartwo=='O'))
                {
                    weekday=true;
                    validDay=true;                                              //flags to check for valid characters entered and whether it is a weekday or weekend
                }
                else if((charone=='T' || charone=='t') && (chartwo=='u'||chartwo=='U'))
                {
                    weekday=true;
                    validDay=true;
                }
                else if((charone=='W' || charone=='w') && (chartwo=='e'||chartwo=='E'))
                {
                    weekday=true;
                    validDay=true;
                }
                else if((charone=='T' || charone=='t') && (chartwo=='h'||chartwo=='H'))
                {
                    weekday=true;
                    validDay=true;
                }
                else if((charone=='F' || charone=='f') && (chartwo=='r'||chartwo=='R'))
                {
                    weekday=true;
                    validDay=true;
                }
                else if((charone=='S' || charone=='s') && (chartwo=='a'||chartwo=='A'))
                {
                    weekday=false;
                    validDay=true;
                    weekend=true;
                }
                else if((charone=='S' || charone=='s') && (chartwo=='u'||chartwo=='U'))
                {
                    weekday=false;
                    validDay=true;
                    weekend=true;
                }
                else {
                    cout <<"Please enter the valid first two letters of the day (uppercase to lowercase)\n";
                    validDay=false;
                }
            }while(validDay==false);                                            //repeats ask if entered wrong

            do
            {
                cout << "Please enter the call length\n";
                cin >> callLength;
            }while(callLength<0);
                                                                                //verifies valid entry for call length
            if (weekday==true)                                                  //checks for verified
            {
                if(startTime<8 || startTime>18)                                 //checks for before 8am and after 6pm
                {
                    bill=0.25*callLength;
                }
                else if(startTime>8 || startTime<18)
                {
                    bill=0.40*callLength;
                }
            }
            else if(weekday==false && weekend==true)                            //checks for weekend
            {
                bill=0.15*callLength;
            }
            cout << "Your bill is $ "<<fixed<<setprecision(2)<<bill<<endl;
            cout << "Would you like to repeat this? Press 'y' for yes and any other key for no: ";
            cin >> repeatchar;
            if (repeatchar=='y')
            {
                repeat=true;
            }
            else
            {
                repeat=false;
                cout << "\nHave a good day\n";
                return 1;
            }
        }while(repeat==true);                                                    //final flag for repeating
    }
