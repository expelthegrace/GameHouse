#include "src/Event.h"

#include <gtest/gtest.h>

TEST(PrimerTest, DemostrarGTestMacros)
{
    int suma = hola();
    EXPECT_EQ(suma, 5);
}