// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IndexedCharacter{

public:
    char _c;
    int _value;
    int _position;
public:
    IndexedCharacter(char c, int value, int position)
    {   
        _c=c;
        _value=value;
        _position=position;
    }

};

class Solution {

public:
    int pos;

public:
    void ErasePastElements(vector<IndexedCharacter> &usedCharacters, int &pos, int iter)
    {   
        int len=usedCharacters.size();

        if(len==0 || iter==len)
        {
            //cout<<"entro aqui";
            return;
        }
        if(usedCharacters[iter]._position<pos)
        {
            cout<<"posicion real: "<<usedCharacters[iter]._position<<" x "<<"posicion del primer elemento repetido: "<<pos<<endl;
            usedCharacters.erase(usedCharacters.begin()+iter);
            return ErasePastElements(usedCharacters, pos,iter);
        }
        
        iter++;
        return ErasePastElements(usedCharacters, pos,iter);
        
    }

public:
    vector<int> CheckandInclude(vector<IndexedCharacter> &usedCharacters, IndexedCharacter &character, int start, int end)
    {
       // std::cout<<start<<"x"<<end<<" "<<character._c<<std::endl;
        int half=static_cast<int> ((start+end)/2);
        if(start>end)
        {
            
            int position = start;

            usedCharacters.insert(usedCharacters.begin() + position, character);
            for(int j=0;j<usedCharacters.size();++j)
                    {
                      std::cout<<usedCharacters[j]._c;
                    }
           std::cout<<std::endl;
            vector<int> result;
            result.push_back(1);
            return result;

        }
        if(usedCharacters[half]._value==character._value)
        {
            //std::cout<<"entro en igualdad de caracteres";
            /*//std::cout<<"value assigned to pos: "<<usedCharacters[half]._position<<std::endl;
            pos=usedCharacters[half]._position;
            std::cout<<"half position: "<<usedCharacters[half]._position<<std::endl;
            usedCharacters[half]._position=character._position;
            std::cout<<"half position: "<<usedCharacters[half]._position<<std::endl;
            //std::cout<<"pos: "<<pos<<std::endl;
            //std::cout<<"character position: "<<character._position<<std::endl;
            std::cout<<"half: "<<half<<std::endl;
            */
            vector<int> result;
            result.push_back(0);
            result.push_back(half);
            return result;
        }

        else if(usedCharacters[half]._value<character._value)
        {
            return CheckandInclude(usedCharacters, character, half+1, end);
        }

        else
        {
            return CheckandInclude(usedCharacters, character, start, half-1);
        }
    }
public:
    int lengthOfLongestSubstring(string s) {
        
        int len= s.size();
        int result=0;

        if(len==0)
        {
            //std::cout<<"entro aqui";
            return result;
        }

        vector<IndexedCharacter> array;
        for(int i=0; i<len;++i)
        {  
            
            array.push_back(IndexedCharacter(s[i],static_cast<int>(s[i]),i));
        }

        vector<IndexedCharacter> usedCharacters;
        usedCharacters.push_back(array[0]);
        result=1;
        //int pos=0;
        int longest=1;
        for(int i=1;i<len;++i)
        {   
            int lenght=usedCharacters.size();
           // std::cout<<"estoy tratando el caracter: "<<array[i]._c<<std::endl;
           // std::cout<<"len de usedCharacters antes: "<<usedCharacters.size()<<std::endl;
            vector<int> check=CheckandInclude(usedCharacters,array[i],0, lenght-1);
           // std::cout<<"len de usedCharacters despues: "<<usedCharacters.size()<<std::endl;
            if(check[0]==1)
            {
                //std::cout<<"entro aqui";
                result++;
                //cout<<"current string len without repetition: "<<result<<endl;
                //if(i==3)
                //{
                  //  for(int j=0;j<usedCharacters.size();++j)
                    //{
                      //std::cout<<usedCharacters[j]._c;
                    //}
                //std::cout<<endl;
                
                //std::cout<<result<<std::endl;
                
                //}
                    
                
                
            }

            else
            {
                    //cout<<"posicion del primer elemento repetido: "<<check[1]<<endl;
                    int firstRepeatedCharacterPos=check[1];
                    //cout<<"firstRepeatedCharacterPos: "<<firstRepeatedCharacterPos<<endl;
                    result=i-usedCharacters[firstRepeatedCharacterPos]._position;
                    //cout<<"current string len without repetition: "<<result<<endl;
                    //cout<<"iteracion: "<<i<<endl;
                    //cout<<"posicion: "<<usedCharacters[firstRepeatedCharacterPos]._position<<endl;
                    
                    //std::cout<<"current position: "<<i<<"  previous character: "<<pos<<std::endl;
                    /*std::cout<<result<<std::endl;
                    for(int i=0; i<usedCharacters.size();++i)
                    {
                        std::cout<<usedCharacters[i]._value;
                    }
                    */
                    /*cout<<"antes"<<endl;
                     for(int j=0;j<usedCharacters.size();++j)
                    {
                      std::cout<<usedCharacters[j]._c;
                    }
                    cout<<endl;
                    */
                    int oldPosition=usedCharacters[firstRepeatedCharacterPos]._position;
                    usedCharacters[firstRepeatedCharacterPos]._position=array[i]._position;
                    ErasePastElements(usedCharacters, oldPosition, 0);
                    //cout<<"antes"<<endl;
                    //cout<<"posicion: "<<usedCharacters[firstRepeatedCharacterPos]._position<<endl;
                    
                    //cout<<"despues"<<endl;
                    //cout<<"posicion: "<<usedCharacters[firstRepeatedCharacterPos]._position<<endl;
                    /*for(int j=0;j<usedCharacters.size();++j)
                    {
                      std::cout<<usedCharacters[j]._c;
                    }
                    */
                    
                   // std::cout<<longest;
                
                
            }
            
            if(result>longest)
                {
                    longest=result;
                }

        }

        return longest;
    }
};
