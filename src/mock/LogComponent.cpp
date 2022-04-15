#include "LogComponent.hpp"

#include <list>
#include <string>

#include "BoardComponent.hpp"
#include "JournalService.hpp"
#include "LoggerService.hpp"
#include "NameComponent.hpp"
#include "Transform2DComponent.hpp"
#include "zombone_engine_types.hpp"
using namespace std;

LogComponent::LogComponent(string name, ObjectIdentifier objectIdentifier)
    : Component(TYPE_COMPONENT_LOG, name, objectIdentifier) {}

void LogComponent::setup() {}

LogComponent::~LogComponent() {}

void LogComponent::input(Input input) { (void)input; }

void LogComponent::render() {}

void LogComponent::setLogIsShowing(int isShowing) { (void)isShowing; }
