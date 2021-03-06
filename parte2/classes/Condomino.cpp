//
// Created by skidr on 25/12/2019.
//

#include "Condomino.h"
#include <sstream>

Condomino::Condomino(string nome, unsigned int nif) : nome(nome), nif(nif){
    this->habitacoes = {};
    this->servicos = {};
}

string Condomino::getNome() const {
    return this->nome;
}

unsigned Condomino::getNIF() const {
    return this->nif;
}

int Condomino::getNumHabitacoes() {
    return this->habitacoes.size();
}

vector<Habitacao *> Condomino::getHabitacoes() {
    return habitacoes;
}

vector<Servico *> Condomino::getServicos() {
    return servicos;
}

string Condomino::info() {
    stringstream os;
    os << "Nome: " << this->nome << endl << "NIF: " << this->nif << endl;
    os << "Numero de Habitaçoes: " << this->getNumHabitacoes();
    return os.str();
}

void Condomino::ordenarHabitacoesArea(bool reverse) {
    int i, j;
    for(j = 1; j < habitacoes.size(); j++)    // Start with 1 (not 0)
    {
        Habitacao *temp = habitacoes[j];
        if (reverse) {
            for (i = j - 1; (i >= 0) && (habitacoes[i]->getAreaHabitacional() <
                                         temp->getAreaHabitacional()); i--)   // Smaller values move up
            {
                habitacoes[i + 1] = habitacoes[i];
            }
        }
        else {
            for (i = j - 1; (i >= 0) && (habitacoes[i]->getAreaHabitacional() >
                                         temp->getAreaHabitacional()); i--)   // Higher values move up
            {
                habitacoes[i + 1] = habitacoes[i];
            }
        }
        habitacoes[i+1] = temp;    //Put key into its proper location
    }
}

void Condomino::ordenarHabitacoesMensalidade(bool reverse) {
    int i, j;
    for(j = 1; j < habitacoes.size(); j++)    // Start with 1 (not 0)
    {
        Habitacao *temp = habitacoes[j];
        if (reverse) {
            for (i = j - 1; (i >= 0) && (habitacoes[i]->mensalidade <
                                         temp->mensalidade); i--)   // Smaller values move up
            {
                habitacoes[i + 1] = habitacoes[i];
            }
        }
        else {
            for (i = j - 1; (i >= 0) && (habitacoes[i]->mensalidade >
                                         temp->mensalidade); i--)   // Higher values move up
            {
                habitacoes[i + 1] = habitacoes[i];
            }
        }
        habitacoes[i+1] = temp;    //Put key into its proper location
    }
}


void Condomino::adicionaHabitacao(Habitacao *hab) {
    this->habitacoes.push_back(hab);
    hab->setEstado(true);
}

void Condomino::removeHabitacao(Habitacao *hab) {
    for (int i = 0; i < habitacoes.size(); i++) {
        if (habitacoes[i] == hab) {
            hab->setEstado(false);
            habitacoes.erase(habitacoes.begin() + i);
            break;
        }
    }
}

float Condomino::mensalidadeTotal() {
    float mens = 0;
    for (Habitacao *habitacao : habitacoes)
        mens += habitacao->mensalidade;
    for (Servico *servico : servicos)
        mens += servico->getCusto();
    return mens;
}

void Condomino::adicionaServico(Servico *serv) {
    this->servicos.push_back(serv);
}

ostream &operator<<(ostream &os, const Condomino &mem) {
    os << "Name: " << mem.nome << endl;
    os << "VAT: " << mem.nif << endl;
    os << "Habitations: " << mem.habitacoes.size() << endl;
    os << "Services: " << mem.servicos.size() << endl;

    float pay = 0;
    for (auto &h : mem.habitacoes) {
        pay += h->mensalidade;
    }
    for (auto &s : mem.servicos) {
        pay += s->getCusto();
    }

    os << "Monthly Payment: " << pay;
}
