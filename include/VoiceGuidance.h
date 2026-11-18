#pragma once
#include <string>
#include <iostream>
class VoiceGuidance {
public:
    virtual ~VoiceGuidance() = default;
    
    virtual void speakWelcome() const = 0;
    virtual void speakPinPrompt() const = 0;
    virtual void speakBalance(double balance) const = 0;
    virtual void speakWithdrawSuccess(double amount) const = 0;
    virtual void speakWithdrawFail() const = 0;
    virtual void speakGoodbye() const = 0;
};

class EnglishVoice : public VoiceGuidance {
public:
    void speakWelcome() const override;
    void speakPinPrompt() const override;
    void speakBalance(double balance) const override;
    void speakWithdrawSuccess(double amount) const override;
    void speakWithdrawFail() const override;
    void speakGoodbye() const override;
};

class FrenchVoice : public VoiceGuidance {
public:
    void speakWelcome() const override;
    void speakPinPrompt() const override;
    void speakBalance(double balance) const override;
    void speakWithdrawSuccess(double amount) const override;
    void speakWithdrawFail() const override;
    void speakGoodbye() const override;
};