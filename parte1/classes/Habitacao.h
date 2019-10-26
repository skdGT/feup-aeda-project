//
// Created by skidr on 12/10/2019.
//

#ifndef PARTE1_HABITACAO_H
#define PARTE1_HABITACAO_H

#include "Morada.h"

/**
 * Classe Habitação
 */
class Habitacao {
protected:
    bool ocupado;           //*< estado "true" para ocupado
    Morada morada;          //*< morada é um objeto da classe Morada
    float areaHabitacional; //*< Área Habitacional da habitação
public:
    /** @brief Construtor da classe Habitação
     *
     * @param morada Objeto morada da classe Morada
     * @param areaHabitacional Área habitacional da habitação
     */
    Habitacao(Morada morada, float areaHabitacional);

    //GET Methods
    /** @brief Método GET da morada da habitação
     *
     * @return Devolve a morada numa string "user-friendly"
     */
    string getMorada();

    /** @brief Método GET da Área Habitacional
     *
     * @return Devolve a área habitacional
     */
    float getAreaHabitacional();
    bool getEstado() { return ocupado; };
    bool setEstado(bool ocupado) {this->ocupado = ocupado; };
    float mensalidade;
};

/**
 * Classe Derivada de Habitação
 */
class Apartamento : public Habitacao {
    string tipologia;   //*< Tipo de apartamento ("T0", "T1", ...)
    int piso;           //*< Número do piso em que o apartamento se encontra
    const string id;
public:

    /** @brief Construtor da classe derivada Apartamento
     *
     * @param morada Objeto morada da classe Morada
     * @param areaHabitacional Área habitacional do apartamento
     * @param tipologia Tipo de apartamento - "T0", "T1", "T2", ...
     * @param piso Piso em que o apartamento se encontra
     */
    Apartamento(Morada morada, float areaHabitacional, string tipologia, int piso, const string id);

    //GET Methods

    /** @brief Método GET da tipologia do apartamento
     *
     * @return Devolve a tipologia do apartamento
     */
    string getTipologia();

    /** @brief Método GET do piso do apartamento
     *
     * @return Devolve o piso em que o apartamento se encontra
     */
    int getPiso();

    //SET Methods

    /** @brief Método SET da tipologia do Apartamento
     *
     * @param tipologia Tipologia a definir o apartamento existente
     */
    void setTipologia(string tipologia);

    /** @brief Método SET do piso do Apartamento
    *
    * @param tipologia Piso a definir o apartamento existente
    */
    void setPiso(int piso);

    virtual string getID() { return id; };
};

/**
 *  Classe Derivada de Habitação
 */
class Vivenda : public Habitacao {
    float areaExterior;    //*< Área exterior da vivenda
    bool piscina;           //*< Existe piscina (sim - true)
    const string id;
public:

    /** @brief Construtor da classe derivada Vivenda
     *
     * @param morada            Objeto morada da classe Morada
     * @param areaHabitacional  Área habitacional da vivenda
     * @param areaExterior      Área exterior da vivenda
     * @param piscina           Existe piscina (sim - true)
     */
    Vivenda(Morada morada, float areaHabitacional, float areaExterior, bool piscina, const string id);

    //GET Methods

    /** @brief Método GET da área exterior da vivenda
     *
     *  @return devolve a área exterior da vivenda
     */
    float getAreaExterior();

    /** @brief Método GET da existencia de piscina na vivenda
     *
     * @return devolve true se existir piscina na vivenda
     */
    bool getPiscina();

    //SET Methods

    /** @brief Método GET da área exterior da vivenda
     *
     * @param areaExterior Valor da área exterior da vivenda
     */
    void setAreaExterior (float areaExterior);

    /** @brief Método SET da existencia de piscina na vivenda
     *
     * @param piscina se existe piscina - true
     */
    void setPiscina (bool piscina);

    string getID() { return id; };
};


#endif //PARTE1_HABITACAO_H
