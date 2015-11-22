#ifndef HAMMING_H_INCLUDED
#define HAMMING_H_INCLUDED



int codificacion(int data);
/**
 * \brief Funcion que realiza la codificacion Hamming
 * \param data valor hasta de 6 bits para codificar
 * \return valor codificado
 */

int decodificacion(int datapp);
/**
 * \brief Funcion que realiza la decodificacion Hamming, ademas corrige un error en la trama si este no presenta paridad
 * \param datapp trama codificada mas paridad
 * \return valord decodificado
 */





#endif // HAMMING_H_INCLUDED
