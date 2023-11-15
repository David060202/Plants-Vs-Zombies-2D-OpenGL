#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateBase(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length, float width,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(width, 0, 0), color),
        VertexFormat(corner + glm::vec3(width, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRomb(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 2*length, 0), color),
        VertexFormat(corner + glm::vec3(2*length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, -2*length, 0), color),
        VertexFormat(corner + glm::vec3(1.8 * length, length / 2 , 0), color),
        VertexFormat(corner + glm::vec3(1.8 * length, -length / 2 , 0), color),
        VertexFormat(corner + glm::vec3(3.2*length, length/2 , 0), color),
        VertexFormat(corner + glm::vec3(3.2*length, -length/2 , 0), color)

    };

    Mesh* romb = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 4, 6, 7, 4, 5, 7 };

    if (!fill) {
        romb->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    romb->InitFromData(vertices, indices);
    return romb;
}

Mesh* object2D::CreateEnemy(
    const std::string& name,
    glm::vec3 center,
    float length,
    glm::vec3 color,
    glm::vec3 color1,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        // vertex for inner hex
        VertexFormat(center + glm::vec3(-2 * length, 0, 1), color),
        VertexFormat(center + glm::vec3(0, 0, 1), color),
        VertexFormat(center + glm::vec3(-length, 1.8 * length, 1), color),
        VertexFormat(center + glm::vec3(length, 1.8*length, 1), color),
        VertexFormat(center + glm::vec3(2 * length, 0, 1), color),
        VertexFormat(center + glm::vec3(length, -1.8 * length, 1), color),
        VertexFormat(center + glm::vec3(-length, -1.8 * length, 1), color),
        // vertext for outer hex
        VertexFormat(center + glm::vec3(0, 0, 0), color1),
        VertexFormat(center + glm::vec3(-3 * length, 0, 0), color1),
        VertexFormat(center + glm::vec3(-1.5 * length, -2.5 * length, 0), color1),
        VertexFormat(center + glm::vec3(1.5 * length, -2.5 * length, 0), color1),
        VertexFormat(center + glm::vec3(3 * length, 0, 0), color1),
        VertexFormat(center + glm::vec3(1.5 * length, 2.5 * length, 0), color1),
        VertexFormat(center + glm::vec3(-1.5 * length, 2.5 * length, 0), color1),

    };

    Mesh* enemy = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 2, 1, 3, 3, 1, 4, 4, 1, 5, 5, 1, 6, 6, 1, 0,
    8, 7, 9, 9, 7, 10, 10, 7, 11, 11, 7, 12, 12, 7, 13, 13, 7, 8};

    if (!fill) {
        enemy->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    enemy->InitFromData(vertices, indices);
    return enemy;
}

Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        // vertex for inner hex
        VertexFormat(center + glm::vec3(-2 * length, length, 0), color),
        VertexFormat(center + glm::vec3(0, -length, 0), color),
        VertexFormat(center + glm::vec3(2 * length, length, 0), color),
        VertexFormat(center + glm::vec3(0, 2 * length, 0), color),
        VertexFormat(center + glm::vec3(-1 * length, 0, 0), color),
        VertexFormat(center + glm::vec3(length, 0, 0), color),
        VertexFormat(center + glm::vec3(-1.6 * length, -1.6 * length, 0), color),
        VertexFormat(center + glm::vec3(1.6 * length, -1.6 * length, 0), color)
    };

    Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2,  3, 4, 5, 6, 4, 1, 7, 5, 1};

    if (!fill) {
        star->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    star->InitFromData(vertices, indices);
    return star;
}