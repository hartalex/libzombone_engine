#include "HealthComponent.hpp"

#include <string>

#include "zombone_engine_types.hpp"
using namespace std;

#define HEALTH_SIZE_MAX 20

HealthComponent::HealthComponent(string name, ObjectIdentifier objectIdentifier)
    : Component(TYPE_COMPONENT_HEALTH, name, objectIdentifier) {}

HealthComponent::~HealthComponent() {}

void HealthComponent::setup() {}

void HealthComponent::add(int additionalHealth) { (void)additionalHealth; }
