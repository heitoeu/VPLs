#include <iostream>
#include <string>
//#include <sstream>

using namespace std;

int main(){
    string tweet;
    string palavra;
    string arrobas, hashtags;
    int contador_arrobas = 0;
    int contador_hashtags = 0;

       
    //stringstream s(tweet);
    
    while (cin >> tweet){
        
        if (tweet[0] == '#')
        {
            contador_hashtags++;
            hashtags = hashtags + "" + tweet;
        }
        
        if (tweet[0] == '@')
        {
            contador_arrobas++;
            arrobas = arrobas + "" + tweet;
        }
    }
    
    if (contador_hashtags != 0){
        cout << "Hashtags: "<< hashtags << endl; 
    }else cout << "O tweet não possui hashtags" << endl;

    if(contador_arrobas != 0){
         
        if (contador_arrobas >= 3)
            {
                cout << "Tweet inválido.";
            }else cout << "Arrobas: " << arrobas << endl;

    }else cout << "O tweet não possui arrobas" << endl;

    return 0;
}