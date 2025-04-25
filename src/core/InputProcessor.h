#pragma once

#include <string>

/**
 * Interface para processadores de entrada
 */

class IInputProcessor {
public:
    virtual ~IInputProcessor() = default;
    virtual std::string ProcessInput(const std::string& ipInput, const std::string& portInput) = 0;     
};

/**
 * implementação concreta agora
 */

class InputProcessor : public IInputProcessor {
public:
    virtual std::string ProcessInput(const std::string& ipInput, const std::string& portInput) override;
};