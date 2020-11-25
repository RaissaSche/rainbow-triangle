#include "ConfigureScene.h"
#include "ManageObj.h"
#include <fstream>
#include <sstream>


ConfigureScene::ConfigureScene() {
	idFog = 0;
}

void ConfigureScene::readFile(string fileName)
{
	ifstream arq(fileName);
	int objsNum;

	while (!arq.eof()) {
		string line;
		getline(arq, line);
		stringstream sline;
		sline << line;
		string temp;
		sline >> temp;

		if (temp == "objsNum") {
			sline >> temp;
			objsNum = stoi(temp);

			for (int i = 0; i < objsNum; i++) {

				getline(arq, line);
				stringstream slineAux;
				slineAux << line;
				string tempAux;
				slineAux >> tempAux;

				ManageObj* manageObj = new ManageObj();
				Obj3D* obj = new Obj3D();
				//path            name Tx Ty Tz S  R Colis�o
				//objs3D/mesa01.obj Mesa1 0 0 0 0.5 45 0

				obj = manageObj->readObj(tempAux);
				slineAux >> tempAux;
				obj->setName(tempAux);
				float tx, ty, tz, s, r;
				slineAux >> tx >> ty >> tz >> s >> r;

				obj->addInfoTransform(tx, ty, tz, s, r);

				slineAux >> tempAux;
				obj->setErasable(tempAux == "1");

				objs.push_back(obj);
			}
		}
		else if (temp == "camera") {
			string token;
			float x, y, z;

			//eye
			sline >> x >> y >> z;
			cameraPos = glm::vec3(x, y, z);

			//direction
			sline >> x >> y >> z;
			cameraTarget = glm::vec3(x, y, z);

			//up
			sline >> x >> y >> z;
			cameraUp = glm::vec3(x, y, z);
		}
		else if (temp == "lightNum") {
			sline >> temp;
			lightNum = stoi(temp);

			for (int i = 0; i < lightNum; i++) {

				getline(arq, line);
				stringstream slineAux;
				slineAux << line;
				string token;

				//position
				float x, y, z;
				slineAux >> x >> y >> z;
				float light[] = { x, y, z };

				lights[i][0] = light[0];
				lights[i][1] = light[1];
				lights[i][2] = light[2];

				if (i == 0) {

					//la
					slineAux >> token;
					setLa(stof(token));

					//ld
					slineAux >> token;
					setLd(stof(token));

					//ls
					slineAux >> token;
					setLs(stof(token));
				}
			}

		}
		else if (temp == "viewport") {
			string token;
			sline >> token;
			width = stoi(token);
			sline >> token;
			height = stoi(token);
		}
		else if (temp == "fog") {
			string token;
			sline >> token;
			if (token == "true") {
				idFog = 1;
				for (int i = 0; i < 3; i++) {
					float x, y, z;
					sline >> x >> y >> z;
					fog = glm::vec3(x, y, z);
				}
			}
		}
		else if (temp == "animFile") {
			string token;
			sline >> token;
			animFile = token;
		}
	}
}

vector<float> ConfigureScene::readAnimationFile()
{
	ifstream arq(animFile);

	while (!arq.eof()) {
		string line;
		getline(arq, line);
		stringstream sline;
		sline << line;
		string temp;

		sline >> temp;
		int bSplineSize = stoi(temp);

		for (int i = 0; i < bSplineSize; i++) {
			sline >> temp;
			animationPath.push_back(stof(temp));
		}
	}
	return animationPath;
}

vector<Obj3D*> ConfigureScene::getObjs()
{
	return objs;
}

glm::mat3 ConfigureScene::getLights()
{
	return lights;
}

glm::vec3 ConfigureScene::getCameraPos()
{
	return cameraPos;
}

glm::vec3 ConfigureScene::getCameraTarget()
{
	return cameraTarget;
}

glm::vec3 ConfigureScene::getCameraUp()
{
	return cameraUp;
}

glm::vec3 ConfigureScene::getFog()
{
	return fog;
}

int ConfigureScene::getWidth()
{
	return width;
}

int ConfigureScene::getHeight()
{
	return height;
}

int ConfigureScene::getLightNum()
{
	return lightNum;
}

int ConfigureScene::getIdFog()
{
	return idFog;
}

void ConfigureScene::setLa(float la)
{
	this->la = la;
}

float ConfigureScene::getLa()
{
	return la;
}

void ConfigureScene::setLd(float ld)
{
	this->ld = ld;
}

float ConfigureScene::getLd()
{
	return ld;
}

void ConfigureScene::setLs(float ls)
{
	this->ls = ls;
}

float ConfigureScene::getLs()
{
	return ls;
}
