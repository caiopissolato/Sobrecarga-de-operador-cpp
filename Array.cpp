#include <iostream>
using std::cout;
using std::ostream;
class Array{
    friend ostream& operator<<(ostream& out, Array &a);

    private:
        int* ptr;
        int tam;
    public:
        //construtr default
        Array(int n){
            if(n > 0){
                this = n;
                ptr new int[n];
                for(int i=0; i<n; i++)
                    ptr[i] = 0;
            }else{
                tam = 0;
            }       
        }
        //construtor por copia
        Array(const Array &a){
            if(this != (&a)){
                ptr = new int[a.tam];
                for(int i=0; i <a.tam; i++)
                this->ptr[i] = a.ptr[i];

                this->tam = a.tam;
            }
        }
        ~Array(){
            if(tam>0)
                delete [] ptr;
                tam = 0;
        }

        //implementar varios operadores
        //operador de atribuiçao
        Array& operator=(const Array& outro){
            if(this != (&outro)){
                if(this->tam != outro.tam){
                    delete [] ptr;
                    ptr = new int[outro.tam];
                    this-> = outro.tam;
                }

                for(int i=0; i<this->tam; i++)
                    ptr[i] = outro.ptr[i];
            }
            return *this; //para encadear a = b = c
        }

        //sobrecarregar operador de soma
        Array operator+(const Array &outro){
            Array aux(this->tam);
            if(this->tam != outro.tam){
                cout<<"Erro: arrays de tamanhos diferentes!\n";
                exit(-1);
            }else{
                Array aux(this->tam);
                for(int i=0; i<this->tam; i++){
                    aux.ptr[i] = this->ptr[i] + outro.ptr[i];
                }
                return aux;
            }
        }

        //sobrecarga do operador ==
        bool operator==(const Array &outro){
            if(this->tam != outro.tam){
                return false;
            }else{
                for(int i=0; i<this->tam; i++){
                    if(this->ptr[i] != outro.ptr[i]){
                        return false;
                    }
                }
                return true;
            }
        }

        //sobrecarrega o operador de indexaçao[]
        int& operator[](const int posicao){
            if((posicao < 0 || (posicao > (tam-1))){
                cout<<"\nErro: acesso indevido!";
                exit(-1);
            }else{
                return this->ptr[posicao];
            }
        }
};

//sobrecarga do operador de extraçao de streams
ostream& operator<<(ostream& out, Array &a){
    for(int i=0; i<a.tam; i++){
        out <<a.ptr[i]<<" ";
        if(((i+1) % 3) == 0)
            out<<"\n";
    }
    return out;
}

int main(){
    Array A1(20);
    A1[0] = 10;
    A1[5] = 7;
    A1[9] = 8;
    A1[3] = 2;

    Array A2(A1);
    A2[9] = 11;
    A2[1] = 50;
    A2[5] = 33;

    cout<<A1<<"\n";
    cout<<A2<<"\n";

    Array A3 = A1 + A2;
    cout<<A3<<"\n";

    if(A1==A2){
        cout<<"Sao iguais.";
    }else{
        cout<<"Sao diferentes.";
    }

    return 0;
}