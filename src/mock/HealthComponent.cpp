#include "HealthComponent.hpp"

#include "types.hpp"
#include <string>

#define HEALTH_SIZE_MAX 20

HealthComponent::HealthComponent(std::string name,
                                 ObjectIdentifier objectIdentifier)
    : Component(TYPE_COMPONENT_HEALTH, name, objectIdentifier) {}

HealthComponent::~HealthComponent() {}

void HealthComponent::setup() {}

void HealthComponent::add(int additionalHealth) { (void)additionalHealth; }
