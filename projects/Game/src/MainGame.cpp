// CreateDefaultScene.cpp
// デフォルトのシーンを生成します

#include <numbers>

#include <UniDx.h>
#include <UniDx/Scene.h>
#include <UniDx/PrimitiveRenderer.h>
#include <UniDx/GltfModel.h>
#include <UniDx/Canvas.h>
#include <UniDx/TextMesh.h>
#include <UniDx/Font.h>
#include <UniDx/Image.h>
#include <UniDx/LightManager.h>

#include "CameraController.h"
#include "Player.h"
#include "LightController.h"

#include <thread>
#include "MainGame.h"


using namespace std;
using namespace UniDx;


void MainGame::createMap()
{
    // マテリアルの作成
    auto wallMat = std::make_shared<Material>();
    auto floorMat = std::make_shared<Material>();
    auto coinMat = std::make_shared<Material>();

    // シェーダを指定してコンパイル
    wallMat->shader->compile<VertexPNT>(u8"resource/AlbedoShadeSpec.hlsl");
    floorMat->shader->compile<VertexPNT>(u8"resource/AlbedoShadeSpec.hlsl");
    floorMat->color = Color(0.85f, 0.8f, 0.85f);
    coinMat->shader->compile<VertexPN>(u8"resource/ShadeSpec.hlsl");
    coinMat->color = Color(1.0f, 0.9f, 0.1f);

    // 床テクスチャ作成
    auto floorTex = std::make_shared<Texture>();
    floorTex->Load(u8"resource/floor.png");
    floorMat->AddTexture(std::move(floorTex));

    // 壁テクスチャ作成
    auto wallTex = std::make_shared<Texture>();
    wallTex->Load(u8"resource/wall.png");
    wallMat->AddTexture(std::move(wallTex));

    // マップ作成
    auto map = make_unique<GameObject>();

    // 床
    auto rb = make_unique<Rigidbody>();
    rb->gravityScale = 0;
    rb->mass = numeric_limits<float>::infinity();
    auto floor = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb),
        make_unique<AABBCollider>());
    floor->transform->localScale = Vector3(5, 1, 5);
    floor->transform->localPosition = Vector3(0, -0.5f, 0);

    // 床右
    auto rb1 = make_unique<Rigidbody>();
    rb1->gravityScale = 0;
    rb1->mass = numeric_limits<float>::infinity();
    auto floor1 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb1),
        make_unique<AABBCollider>());
    floor1->transform->localScale = Vector3(5, 1, 5);
    floor1->transform->localPosition = Vector3(5, -0.5f, 0);

    // 床左
    auto rb2 = make_unique<Rigidbody>();
    rb2->gravityScale = 0;
    rb2->mass = numeric_limits<float>::infinity();
    auto floor2 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb2),
        make_unique<AABBCollider>());
    floor2->transform->localScale = Vector3(5, 1, 5);
    floor2->transform->localPosition = Vector3(-5, -0.5f, 0);


    auto rb3 = make_unique<Rigidbody>();
    rb3->gravityScale = 0;
    rb3->mass = numeric_limits<float>::infinity();
    auto floor3 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb3),
        make_unique<AABBCollider>());
    floor3->transform->localScale = Vector3(5, 1, 5);
    floor3->transform->localPosition = Vector3(0, -0.5f, -5);


    auto rb4 = make_unique<Rigidbody>();
    rb4->gravityScale = 0;
    rb4->mass = numeric_limits<float>::infinity();
    auto floor4 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb4),
        make_unique<AABBCollider>());
    floor4->transform->localScale = Vector3(5, 1, 5);
    floor4->transform->localPosition = Vector3(5, -0.5f, -5);


    auto rb5 = make_unique<Rigidbody>();
    rb5->gravityScale = 0;
    rb5->mass = numeric_limits<float>::infinity();
    auto floor5 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb5),
        make_unique<AABBCollider>());
    floor5->transform->localScale = Vector3(5, 1, 5);
    floor5->transform->localPosition = Vector3(-5, -0.5f, -5);


    auto rb6 = make_unique<Rigidbody>();
    rb6->gravityScale = 0;
    rb6->mass = numeric_limits<float>::infinity();
    auto floor6 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb6),
        make_unique<AABBCollider>());
    floor6->transform->localScale = Vector3(5, 1, 5);
    floor6->transform->localPosition = Vector3(0, -0.5f, -10);


    auto rb7 = make_unique<Rigidbody>();
    rb7->gravityScale = 0;
    rb7->mass = numeric_limits<float>::infinity();
    auto floor7 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb7),
        make_unique<AABBCollider>());
    floor7->transform->localScale = Vector3(5, 1, 5);
    floor7->transform->localPosition = Vector3(5, -0.5f, -10);


    auto rb8 = make_unique<Rigidbody>();
    rb8->gravityScale = 0;
    rb8->mass = numeric_limits<float>::infinity();
    auto floor8 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb8),
        make_unique<AABBCollider>());
    floor8->transform->localScale = Vector3(5, 1, 5);
    floor8->transform->localPosition = Vector3(-5, -0.5f, -10);


    auto rb9 = make_unique<Rigidbody>();
    rb9->gravityScale = 0;
    rb9->mass = numeric_limits<float>::infinity();
    auto floor9 = make_unique<GameObject>(u8"床",
        CubeRenderer::create<VertexPNT>(floorMat),
        move(rb9),
        make_unique<AABBCollider>());
    floor9->transform->localScale = Vector3(5, 1, 5);
    floor9->transform->localPosition = Vector3(0, -0.5f, -20);


    // 親をマップにする
    Transform::SetParent(move(floor), map->transform);
    Transform::SetParent(move(floor1), map->transform);
    Transform::SetParent(move(floor2), map->transform);
    Transform::SetParent(move(floor3), map->transform);
    Transform::SetParent(move(floor4), map->transform);
    Transform::SetParent(move(floor5), map->transform);
    Transform::SetParent(move(floor6), map->transform);
    Transform::SetParent(move(floor7), map->transform);
    Transform::SetParent(move(floor8), map->transform);
    Transform::SetParent(move(floor9), map->transform);

    // 壁
    rb = make_unique<Rigidbody>();
    rb->gravityScale = 0;
    rb->mass = numeric_limits<float>::infinity();
    auto wall = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb),
        make_unique<AABBCollider>());
    wall->transform->localScale = Vector3(5, 2, 1);
    wall->transform->localPosition = Vector3(0, 0.5f, 3);

    // 壁右
    rb1 = make_unique<Rigidbody>();
    rb1->gravityScale = 0;
    rb1->mass = numeric_limits<float>::infinity();
    auto wall1 = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb1),
        make_unique<AABBCollider>());
    wall1->transform->localScale = Vector3(5, 2, 1);
    wall1->transform->localPosition = Vector3(5, 0.5f, 3);

    // 壁左
    rb2 = make_unique<Rigidbody>();
    rb2->gravityScale = 0;
    rb2->mass = numeric_limits<float>::infinity();
    auto wall2 = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb2),
        make_unique<AABBCollider>());
    wall2->transform->localScale = Vector3(5, 2, 1);
    wall2->transform->localPosition = Vector3(-5, 0.5f, 3);


    rb3 = make_unique<Rigidbody>();
    rb3->gravityScale = 0;
    rb3->mass = numeric_limits<float>::infinity();
    auto wall3 = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb3),
        make_unique<AABBCollider>());
    wall3->transform->localScale = Vector3(1, 2, 5);
    wall3->transform->localPosition = Vector3(-8, 0.5f, 0);


    rb4 = make_unique<Rigidbody>();
    rb4->gravityScale = 0;
    rb4->mass = numeric_limits<float>::infinity();
    auto wall4 = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb4),
        make_unique<AABBCollider>());
    wall4->transform->localScale = Vector3(1, 2, 5);
    wall4->transform->localPosition = Vector3(-8, 0.5f, -5);


    rb5 = make_unique<Rigidbody>();
    rb5->gravityScale = 0;
    rb5->mass = numeric_limits<float>::infinity();
    auto wall5 = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb5),
        make_unique<AABBCollider>());
    wall5->transform->localScale = Vector3(1, 2, 5);
    wall5->transform->localPosition = Vector3(-8, 0.5f, -10);


    rb6 = make_unique<Rigidbody>();
    rb6->gravityScale = 0;
    rb6->mass = numeric_limits<float>::infinity();
    auto wall6 = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb6),
        make_unique<AABBCollider>());
    wall6->transform->localScale = Vector3(5, 2, 1);
    wall6->transform->localPosition = Vector3(0, 0.5f, -13);


    rb7 = make_unique<Rigidbody>();
    rb7->gravityScale = 0;
    rb7->mass = numeric_limits<float>::infinity();
    auto wall7 = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb7),
        make_unique<AABBCollider>());
    wall7->transform->localScale = Vector3(5, 2, 1);
    wall7->transform->localPosition = Vector3(5, 0.5f, -13);


    rb8 = make_unique<Rigidbody>();
    rb8->gravityScale = 0;
    rb8->mass = numeric_limits<float>::infinity();
    auto wall8 = make_unique<GameObject>(u8"壁",
        CubeRenderer::create<VertexPNT>(wallMat),
        move(rb8),
        make_unique<AABBCollider>());
    wall8->transform->localScale = Vector3(5, 2, 1);
    wall8->transform->localPosition = Vector3(-5, 0.5f, -13);


    // 親をマップにする
    Transform::SetParent(move(wall), map->transform);
    Transform::SetParent(move(wall1), map->transform);
    Transform::SetParent(move(wall2), map->transform);
    Transform::SetParent(move(wall3), map->transform);
    Transform::SetParent(move(wall4), map->transform);
    Transform::SetParent(move(wall5), map->transform);
    Transform::SetParent(move(wall6), map->transform);
    Transform::SetParent(move(wall7), map->transform);
    Transform::SetParent(move(wall8), map->transform);

    // コインオブジェクトを作成
    auto coin = make_unique<GameObject>(u8"Coin",
        SphereRenderer::create<VertexPT>(u8"resource/Albedo.hlsl", u8"resource/wall.png"),
        make_unique<Rigidbody>(),
        make_unique<SphereCollider>(Vector3(0, -0.1f, 0), 0.4f)
    );
    coin->transform->localPosition = Vector3(2, 1, 0);
    Transform::SetParent(move(coin), map->transform);

    mapObj = move(map);
}


unique_ptr<UniDx::Scene> MainGame::CreateScene()
{
    // -- プレイヤー --
    auto playerObj = make_unique<GameObject>(u8"プレイヤー",
        make_unique<GltfModel>(),
        make_unique<Rigidbody>(),
        make_unique<SphereCollider>(Vector3(0, 0.5f, 0)),
        make_unique<Player>()
        );
    auto model = playerObj->GetComponent<GltfModel>(true);
    model->Load<VertexSkin>(
        u8"resource/ModularCharacterPBR.glb",
        u8"resource/SkinBasic.hlsl");
    playerObj->transform->localPosition = Vector3(0, 0, 0);
    playerObj->transform->localRotation = Quaternion::Euler(0, 180, 0);

    // -- カメラ --
    auto cameraBehaviour = make_unique<CameraController>();
    cameraBehaviour->player = playerObj->GetComponent<Player>(true);

    // -- ライト --
    LightManager::getInstance()->ambientColor = Color(0.4f, 0.4f, 0.4f, 1.0f);
    auto light = make_unique<GameObject>(u8"ディレクショナルライト", make_unique<Light>());
    light->transform->localPosition = Vector3(4, 3, -3);
    light->transform->localRotation = Quaternion::Euler(30, 60, 0.0f);

    // -- UI --
    auto font = make_shared<Font>();
    font->Load(u8"resource/M PLUS 1.spritefont");
    auto textMesh = make_unique<TextMesh>();
    textMesh->font = font;
    textMesh->text = u8"WASD:いどう\nIJKL:カメラ";

    auto textObj = make_unique<GameObject>(u8"テキスト", textMesh);
    textObj->transform->localPosition = Vector3(100, 20, 0);
    textObj->transform->localScale = Vector3(0.6f, 0.6f, 1.0f);

    auto scoreMesh = make_unique<TextMesh>();
    scoreMesh->font = font;
    scoreMesh->text = u8"0";
    scoreTextMesh = scoreMesh.get();

    auto scoreTextObj = make_unique<GameObject>(u8"スコア", scoreMesh);
    scoreTextObj->transform->localPosition = Vector3(480, 20, 0);

    auto canvas = make_unique<Canvas>();
    canvas->LoadDefaultMaterial(u8"resource");

    // -- マップデータ --
    createMap();

    // シーンを作って戻す
    return make_unique<Scene>(

        make_unique<GameObject>(u8"オブジェクトルート",
            move(playerObj),
            move(mapObj)
        ),

        move(light),

        make_unique<GameObject>(u8"カメラルート", Vector3(0, 3, -5),
            make_unique<Camera>(),
            move(cameraBehaviour)
        ),

        make_unique<GameObject>(u8"UI",
            move(canvas),
            move(textObj),
            move(scoreTextObj)
        )
    );
}


MainGame::~MainGame()
{
}


void MainGame::AddScore(int n)
{
    score += n;
    scoreTextMesh->text = ToString(score);
}
