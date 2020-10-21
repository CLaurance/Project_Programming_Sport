#include <iostream>
#include <limits>

using namespace std;



int check_char(int x){
    while(cin.fail() || x<0 || x>10){
        cin.clear();                                                                        //to clear the buffer memory
        cin.ignore(numeric_limits<streamsize>::max(),'\n');                                //ignore all the input the user has provided
        cout << "Please enter a valid input : ";
        cin >> x;
    }
    return x;
}


int check_limit(int x){

    while(x<0 || x>10){
        cout << "Please enter a valid input : ";
        cin >> x;
    }
    return x;
}


int get_input (int x){                                                                              //check for correct user input
    cin>>x;
    x = check_limit(x);
    x = check_char(x);



    return x;
}


int main()
{
    int score[30], total = 0;
    int round[3] = {0, 0, 0};
                                                                                                    //variables declaration
    for (int j = 0; j<3; j++){                                                                     //Do 3 rounds

        for (int i = 0; i<10; i++){


            score[i+(j*10)] = get_input(score[i+(j*10)]);
            round[j] += score[i+(j*10)];
                                                                                                    //add to round score
        }

        total += round[j];
        cout << round[j]<<endl;                                                                   //add to total score and show round score

    }
    cout << total <<endl;

    for (int k = 1; k<31; k++){                                                                    //print total score and individual arrow score
        cout << score[k-1]<<" ";

        if(k%10 == 0 ){
            cout <<round[(k/10)-1]<<endl;                                                           //print all the scores for each turn
        }

    }
}




