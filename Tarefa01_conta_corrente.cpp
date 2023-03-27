//============================================================================
// Name        : thaine.cpp
// Author      : thaine
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class ContaCorrente {
private:
    double saldo;
    double taxa = 0.005;
public:
    ContaCorrente(double saldo_inicial = 0.0) {
        saldo = saldo_inicial; //conta corrente recebe o saldo inicial de 0 reais
    }

    void deposito(double valor) {
        saldo += valor;//recebe o valor requerido no main, para o deposito
        std::cout << "Depósito de R$" << valor << " realizado com sucesso." << std::endl;
    }

    void saque(double valor) {

        if (saldo >= valor + (valor * taxa))
        {
            saldo -= valor + (valor * taxa); //diminui do saldo o valor informado no main
            std::cout << "Saque de  R$" << valor << " realizado com sucesso." << std::endl;
        }
        else
        {
            std::cout << "Saldo insuficiente." << std::endl;
        }
    }

    double obterSaldo() const {
        return saldo; //Informa o saldo na conta
    }
};

int main() {
    ContaCorrente minhaConta(1000.0); //informa que tem 1000 reais na conta corrente
    std::cout << "Saldo atual: R$" << minhaConta.obterSaldo() << std::endl;

    minhaConta.deposito(100.0); // deposita 100 reais na conta corrente
    std::cout << "Saldo atual: R$" << minhaConta.obterSaldo() << std::endl;

    minhaConta.saque(100.0); //retira 100 reais da conta corrente
    std::cout << "Saldo atual: R$" << minhaConta.obterSaldo() << std::endl;

    return 0;
}

