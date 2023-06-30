#ifndef ENGINESSET
#define ENGINESSET

#include "Engine.hpp"
#include "SDCard.hpp"
#include <vector>
#include <string>
#include <Arduino.h>

class EnginesSet
{
public:

    enum mDirection
    {
        UP = 0,
        DOWN = 1
    };

    EnginesSet();

    void insertMotor(char pGuitarString, int pStep, int pDir);

    // void boot(); // Lógica de fim de curso

    // adiciona os motores que irão girar de acordo com a corda presente na música
    void addToenginesToPlay(std::string pGuitarString);

    // roda o motor antes adicionado
    void playMany();

    // toca a música
    void parseFile(std::string pStream, int pTune);

    // faz subida ou descida em todos os motores
    void runThrough(mDirection pDirection);

    void tune(int pTunePosition);

    // reseta o motor selecionado
    void playOneStep(int pGuitarReset, int pSignal);

    void getEnginePos(SDCard pSd);

    //Configura oposição após cada música
    void endMusic();

    // configura velocidade a cada motor
    void setEngineSpeed(SDCard pSd); 

    //determina o número de subdivisões de um compasso
    void setSubdivision(SDCard pSd);

    //determina e retorna o delay entre um pulso e outro
    void setDelay();

    void setCurrentTarget(String pcurrentTargets);

    void runHalfTarget(int pGuitarStringReset);

    std::vector<int> mEnginePos;

private:
    std::vector<Engine *> mEngines;
    std::vector<Engine *> mEnginesToPlay;
    // int mExitLoop;
    // int mButtonUpState;
    // int mButtonSelectState;
    // int mButtonDownState;
    float mBPMSpeed; 
    string mSubdivision;
    int mGlobalTargets;
    int mDelayMilis;
    int mDelayMicro;
};

#endif