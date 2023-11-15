#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateRomb(const std::string& name, glm::vec3 leftCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateBase(const std::string& name, glm::vec3 leftBottomCorner, float length, float width, glm::vec3 color, bool fill = false);
    Mesh* CreateEnemy(const std::string& name, glm::vec3 center, float length, glm::vec3 color, glm::vec3 color1,bool fill = false);
    Mesh* CreateStar(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);

}
