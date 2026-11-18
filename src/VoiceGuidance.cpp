// src/VoiceGuidance.cpp
#include "VoiceGuidance.h"
#include <iostream>

// --- English Voice ---
void EnglishVoice::speakWelcome() const {
    std::cout << "[Voice]: Welcome to the ATM.\n";
}
void EnglishVoice::speakPinPrompt() const {
    std::cout << "[Voice]: Please enter your 4-digit PIN.\n";
}
void EnglishVoice::speakBalance(double balance) const {
    std::cout << "[Voice]: Your current balance is $" << balance << "\n";
}
void EnglishVoice::speakWithdrawSuccess(double amount) const {
    std::cout << "[Voice]: Please take your cash: $" << amount << "\n";
}
void EnglishVoice::speakWithdrawFail() const {
    std::cout << "[Voice]: Transaction failed. Insufficient funds.\n";
}
void EnglishVoice::speakGoodbye() const {
    std::cout << "[Voice]: Thank you for using our ATM. Goodbye.\n";
}

// --- French Voice ---
void FrenchVoice::speakWelcome() const {
    std::cout << "[Voix]: Bienvenue à l'ATM.\n";
}
void FrenchVoice::speakPinPrompt() const {
    std::cout << "[Voix]: Veuillez entrer votre code PIN.\n";
}
void FrenchVoice::speakBalance(double balance) const {
    std::cout << "[Voix]: Votre solde est de $" << balance << "\n";
}
void FrenchVoice::speakWithdrawSuccess(double amount) const {
    std::cout << "[Voix]: Prenez vos espèces: $" << amount << "\n";
}
void FrenchVoice::speakWithdrawFail() const {
    std::cout << "[Voix]: Échec de la transaction. Fonds insuffisants.\n";
}
void FrenchVoice::speakGoodbye() const {
    std::cout << "[Voix]: Merci d'avoir utilisé notre ATM. Au revoir.\n";
}