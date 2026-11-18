// include/VoiceGuidance.h
#pragma once
#include <string>
#include <iostream>

// Abstract base class (OOP Requirement)
class VoiceGuidance {
public:
    virtual ~VoiceGuidance() = default;
    
    // Pure virtual functions (must be implemented by derived classes)
    virtual void speakWelcome() const = 0;
    virtual void speakPinPrompt() const = 0;
    virtual void speakBalance(double balance) const = 0;
    virtual void speakWithdrawSuccess(double amount) const = 0;
    virtual void speakWithdrawFail() const = 0;
    virtual void speakGoodbye() const = 0;
};

// English Implementation
class EnglishVoice : public VoiceGuidance {
public:
    void speakWelcome() const override;
    void speakPinPrompt() const override;
    void speakBalance(double balance) const override;
    void speakWithdrawSuccess(double amount) const override;
    void speakWithdrawFail() const override;
    void speakGoodbye() const override;
};

// French Implementation (Satisfies FR20 - Language Selection)
class FrenchVoice : public VoiceGuidance {
public:
    void speakWelcome() const override;
    void speakPinPrompt() const override;
    void speakBalance(double balance) const override;
    void speakWithdrawSuccess(double amount) const override;
    void speakWithdrawFail() const override;
    void speakGoodbye() const override;
};