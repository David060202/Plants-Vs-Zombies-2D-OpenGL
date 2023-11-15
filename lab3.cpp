#include "lab_m1/lab3/lab3.h"

#include <vector>
#include <iostream>

#include "lab_m1/lab3/transform2D.h"
#include "lab_m1/lab3/object2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Lab3::Lab3()
{
}


Lab3::~Lab3()
{
}


void Lab3::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner_baseline = glm::vec3(20, 40, 0);

    glm::vec3 corner_row_1_1 = glm::vec3(110, 40, 0);
    glm::vec3 corner_row_1_2 = glm::vec3(110, 200, 0);
    glm::vec3 corner_row_1_3 = glm::vec3(110, 360, 0);

    glm::vec3 corner_row_2_1 = glm::vec3(265, 40, 0);
    glm::vec3 corner_row_2_2 = glm::vec3(265, 200, 0);
    glm::vec3 corner_row_2_3 = glm::vec3(265, 360, 0);

    glm::vec3 corner_row_3_1 = glm::vec3(420, 40, 0);
    glm::vec3 corner_row_3_2 = glm::vec3(420, 200, 0);
    glm::vec3 corner_row_3_3 = glm::vec3(420, 360, 0);

    glm::vec3 corner_romb_1 = glm::vec3(30, 620, 0);
    glm::vec3 corner_romb_2 = glm::vec3(180, 620, 0);
    glm::vec3 corner_romb_3 = glm::vec3(330, 620, 0);
    glm::vec3 corner_romb_4 = glm::vec3(480, 620, 0);

    glm::vec3 corner_square_romb_1 = glm::vec3(10, 555, 0);
    glm::vec3 corner_square_romb_2 = glm::vec3(160, 555, 0);
    glm::vec3 corner_square_romb_3 = glm::vec3(310, 555, 0);
    glm::vec3 corner_square_romb_4 = glm::vec3(460, 555, 0);

    glm::vec3 center_enemy_1 = glm::vec3(800, 105, 0);
    glm::vec3 center_enemy_2 = glm::vec3(800, 265, 0);
    glm::vec3 center_enemy_3 = glm::vec3(800, 425, 0);
    glm::vec3 center_enemy_4 = glm::vec3(800, 585, 0);

    glm::vec3 center_star_1 = glm::vec3(900, 105, 0);
    glm::vec3 center_star_2 = glm::vec3(900, 265, 0);
    glm::vec3 center_star_3 = glm::vec3(900, 425, 0);
    glm::vec3 center_star_4 = glm::vec3(900, 585, 0);





    //glm::vec3 corner2 = glm::vec3(250, 0, 0);
    //glm::vec3 corner3 = glm::vec3(570, 0, 0);

    float base_width = 70;
    float base_length = 450;
    float squareSide = 130;
    float squareSide1 = 120;
    float romb_length = 25;
    float enemy_length = 12;
    float star_length = 17;

    // TODO(student): Compute coordinates of a square's center, and store
    // then in the `cx` and `cy` class variables (see the header). Use
    // `corner` and `squareSide`. These two class variables will be used
    // in the `Update()` function. Think about it, why do you need them?

    // Initialize tx and ty (the translation steps)
    translateX = 0;
    translateX_star = 0;
    translateY = 0;

    // Initialize sx and sy (the scale factors)
    scaleX = 1;
    scaleY = 1;

    // Initialize angularStep
    angularStep = 800;
    
    Mesh* base = object2D::CreateBase("base", corner_baseline, base_length, base_width, glm::vec3(1, 0, 0), true);
    AddMeshToList(base);

    Mesh* square1_1 = object2D::CreateSquare("square1_1", corner_row_1_1, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square1_1);
    Mesh* square1_2 = object2D::CreateSquare("square1_2", corner_row_1_2, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square1_2);
    Mesh* square1_3 = object2D::CreateSquare("square1_3", corner_row_1_3, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square1_3);

    Mesh* square2_1 = object2D::CreateSquare("square2_1", corner_row_2_1, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square2_1);
    Mesh* square2_2 = object2D::CreateSquare("square2_2", corner_row_2_2, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square2_2);
    Mesh* square2_3 = object2D::CreateSquare("square2_3", corner_row_2_3, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square2_3);

    Mesh* square3_1 = object2D::CreateSquare("square3_1", corner_row_3_1, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square3_1);
    Mesh* square3_2 = object2D::CreateSquare("square3_2", corner_row_3_2, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square3_2);
    Mesh* square3_3 = object2D::CreateSquare("square3_3", corner_row_3_3, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square3_3);

    Mesh* romb_1 = object2D::CreateRomb("romb_1", corner_romb_1, romb_length, glm::vec3(1, 0.55, 0), true);
    AddMeshToList(romb_1);
    Mesh* romb_2 = object2D::CreateRomb("romb_2", corner_romb_2, romb_length, glm::vec3(0, 0, 1), true);
    AddMeshToList(romb_2);
    Mesh* romb_3 = object2D::CreateRomb("romb_3", corner_romb_3, romb_length, glm::vec3(1, 1, 0), true);
    AddMeshToList(romb_3);
    Mesh* romb_4 = object2D::CreateRomb("romb_4", corner_romb_4, romb_length, glm::vec3(0.6, 0, 0.8), true);
    AddMeshToList(romb_4);

    Mesh* square_romb_1 = object2D::CreateSquare("square_romb_1", corner_square_romb_1, squareSide1, glm::vec3(1, 0.55, 0), false);
    AddMeshToList(square_romb_1);
    Mesh* square_romb_2 = object2D::CreateSquare("square_romb_2", corner_square_romb_2, squareSide1, glm::vec3(0, 0, 1), false);
    AddMeshToList(square_romb_2);
    Mesh* square_romb_3 = object2D::CreateSquare("square_romb_3", corner_square_romb_3, squareSide1, glm::vec3(1, 1, 0), false);
    AddMeshToList(square_romb_3);
    Mesh* square_romb_4 = object2D::CreateSquare("square_romb_4", corner_square_romb_4, squareSide1, glm::vec3(0.6, 0, 0.8), false);
    AddMeshToList(square_romb_4);

    Mesh* enemy_1 = object2D::CreateEnemy("enemy_1", center_enemy_1, enemy_length, glm::vec3(0.16, 0.6, 0.52), glm::vec3(1, 0.55, 0),true);
    AddMeshToList(enemy_1);
    Mesh* enemy_2 = object2D::CreateEnemy("enemy_2", center_enemy_2, enemy_length, glm::vec3(0.16, 0.6, 0.52), glm::vec3(0, 0, 1), true);
    AddMeshToList(enemy_2);
    Mesh* enemy_3 = object2D::CreateEnemy("enemy_3", center_enemy_3, enemy_length, glm::vec3(0.16, 0.6, 0.52), glm::vec3(1, 1, 0), true);
    AddMeshToList(enemy_3);
    Mesh* enemy_4 = object2D::CreateEnemy("enemy_4", center_enemy_4, enemy_length, glm::vec3(0.16, 0.6, 0.52), glm::vec3(0.6, 0, 0.8), true);
    AddMeshToList(enemy_4);

    Mesh* star_1 = object2D::CreateStar("star_1", center_star_1, star_length, glm::vec3(1, 0.55, 0), true);
    AddMeshToList(star_1);
    Mesh* star_2 = object2D::CreateStar("star_2", center_star_2, star_length, glm::vec3(0, 0, 1), true);
    AddMeshToList(star_2);
    Mesh* star_3 = object2D::CreateStar("star_3", center_star_3, star_length, glm::vec3(1, 1, 0), true);
    AddMeshToList(star_3);
    Mesh* star_4 = object2D::CreateStar("star_4", center_star_4, star_length, glm::vec3(0.6, 0, 0.8), true);
    AddMeshToList(star_4);

}


void Lab3::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Lab3::Update(float deltaTimeSeconds)
{
    // TODO(student): Update steps for translation, rotation and scale,
    // in order to create animations. Use the class variables in the
    // class header, and if you need more of them to complete the task,
    // add them over there!

    modelMatrix = glm::mat3(1);
    //modelMatrix *= transform2D::Rotate(angularStep);
    //modelMatrix *= transform2D::Translate(150, 350);
    // TODO(student): Create animations by multiplying the current
    // transform matrix with the matrices you just implemented.
    // Remember, the last matrix in the chain will take effect first!
    // red rectangle for base
    RenderMesh2D(meshes["base"], shaders["VertexColor"], modelMatrix);
    
    // first column of green squares
    RenderMesh2D(meshes["square1_1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square1_2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square1_3"], shaders["VertexColor"], modelMatrix);
    // second column of green squares
    RenderMesh2D(meshes["square2_1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square2_2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square2_3"], shaders["VertexColor"], modelMatrix);
    // third column of green squares
    RenderMesh2D(meshes["square3_1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square3_2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square3_3"], shaders["VertexColor"], modelMatrix);
    //
    RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);

    RenderMesh2D(meshes["square_romb_1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square_romb_2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square_romb_3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["square_romb_4"], shaders["VertexColor"], modelMatrix);





    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX, translateY);
    translateX -= 32*deltaTimeSeconds;
    RenderMesh2D(meshes["enemy_1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["enemy_2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["enemy_3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["enemy_4"], shaders["VertexColor"], modelMatrix);


    modelMatrix = glm::mat3(1);
    //angularStep += deltaTimeSeconds;
    //translateX_star += deltaTimeSeconds * 32;
    modelMatrix *= transform2D::Translate(translateX_star, translateY);
    //modelMatrix *= transform2D::Rotate(angularStep);
    RenderMesh2D(meshes["star_1"], shaders["VertexColor"], modelMatrix);
    modelMatrix = glm::mat3(1);
    RenderMesh2D(meshes["star_2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star_3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["star_4"], shaders["VertexColor"], modelMatrix);


    //modelMatrix = glm::mat3(1);
    //modelMatrix *= transform2D::Translate(650, 450);
    // TODO(student): Create animations by multiplying the current
    // transform matrix with the matrices you just implemented
    // Remember, the last matrix in the chain will take effect first!

}


void Lab3::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Lab3::OnInputUpdate(float deltaTime, int mods)
{
}


void Lab3::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Lab3::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Lab3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Lab3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Lab3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Lab3::OnWindowResize(int width, int height)
{
}
