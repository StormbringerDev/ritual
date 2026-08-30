#include <ritual/platform/window.hpp>

#include <gtest/gtest.h>

TEST(Window, WindowPropsHasCorrectValues) {
  ritual::WindowProps props{640, 480, "Test Window", true};
  EXPECT_EQ(props.width, 640);
  EXPECT_EQ(props.height, 480);
  EXPECT_EQ(props.title, "Test Window");
  EXPECT_TRUE(props.resizable);
}

TEST(Window, WindowPropsHasCorrectDefaults) {
  ritual::WindowProps props;
  EXPECT_EQ(props.width, 640);
  EXPECT_EQ(props.height, 480);
  EXPECT_EQ(props.title, "Ritual");
  EXPECT_TRUE(props.resizable);
}