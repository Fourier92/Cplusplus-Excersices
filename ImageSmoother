#include <array>

class Solution {

    float filter(int rowBegin, int rowEnd, int columnBegin, int columnEnd, vector<vector<int>>& img)
    {
        std::cout <<rowBegin<<'x'<<rowEnd<<'x'<<columnBegin<<'x'<<columnEnd<< std::endl;
        float sum=0;
        int numberOfElements=(rowEnd-rowBegin+1)*(columnEnd-columnBegin+1);

        for (int i=rowBegin; i<=rowEnd; ++i)
        {
            for(int j=columnBegin; j<=columnEnd; ++j)
            {
                std::cout << "esta entrando en"<<i<<'x'<<j << std::endl;
                sum=sum+img[i][j];
            }
        }

        return sum/numberOfElements;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int rows=end(img)-begin(img);
        int columns=end(img[0])-begin(img[0]);

        std::cout <<rows<<'x'<<columns << std::endl;

        vector<vector<int>> result;
        result.resize(rows);

        for(int i=0; i<rows; ++i)
        {
             result[i].resize(columns);
   
            for(int j=0; j<columns; ++j)
            {
                 if (rows==1)
                {
                    std::cout << "esta entrando en fila 1." << std::endl;
                    if(columns==1)
                     {
                         result[i][j]=img[i][j];
                         return result;
                     }

                    else
                    {   
                        std::cout << "esta entrando en fila 1, mas de una columna." << std::endl;
                        std::cout << "j: "<<j << std::endl;
                        if(j==0)
                        {
                            std::cout <<i<<'x'<<i<<'x'<<j<<'x'<<j+1 << std::endl;
                            result[i][j]=filter(i,i,j,j+1,img);
                            std::cout << "esta resolviendo el primero" << std::endl;
                        }
                        
                        else if(j==columns-1)
                        {
                            result[i][j]=filter(0,0,j-1,j,img);
                        }

                        else
                        {
                            result[i][j]=filter(0,0,j-1,j+1,img);
                        }
                    }
    
                }
                else if(columns==1)
                    { 
                        std::cout<<'esta entrando en 1 columna'<< std::endl;
                        if(i==0)
                        {
                            result[i][j]=filter(0,1,j,j,img);
                        }

                        else if(i==rows-1)
                        {
                            result[i][j]=filter(i-1,i,j,j,img);
                        }

                        else
                        {
                            result[i][j]=filter(i-1,i+1,j,j,img);
                        }
                    }

                else
                {
                    std:: cout<<"esta entrando en varias columnas y varias filas"<< std::endl;
                    std::cout <<i<<'x'<<i<<'x'<<j<<'x'<<j+1 << std::endl;
                    if(i==0)
                        {
                            if(j==0)
                                {
                                  result[i][j]=filter(0,1,0,1,img);
                                }

                            else if(j==columns-1)
                                {
                                   result[i][j]=filter(0,1,j-1,j,img);
                                }

                            else
                                {
                                    std:: cout<<"entro en la casilla"<<i<<"x"<<j<< std::endl;
                                   result[i][j]=filter(0,1,j-1,j+1,img);
                                }
                        }

                    else if(i==rows-1)
                        {
                          if(j==0)
                              {
                                 result[i][j]=filter(i-1,i,0,1,img);
                              }

                         else if(j==columns-1)
                             {
                                result[i][j]=filter(i-1, i, j-1, j,img);
                             }

                         else
                             {
                              result[i][j]=filter(i-1, i, j-1, j+1,img);
                             }
                        }

                    else
                     {
                        if(j==0)
                       {
                            result[i][j]=filter(i-1,i+1,0,1, img);
                       }

                        else if(j==columns-1)
                        {
                            result[i][j]=filter(i-1, i+1,j-1,j, img);
                        }

                        else
                        {
                            result[i][j]=filter(i-1, i+1, j-1, j+1,img);
                        }
                }
            }
            }
        }
            
                
        return result;
    }
};
