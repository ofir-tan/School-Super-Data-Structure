#include "Layer.h"

Layer::~Layer() {
    for (auto &class_: classes)
        delete class_;
}