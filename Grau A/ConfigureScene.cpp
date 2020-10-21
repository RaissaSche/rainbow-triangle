#include "ConfigureScene.h"
#include "ManageObj.h"
#include <fstream>
#include <sstream>

void ConfigureScene::readFile(string fileName)
{
	ifstream arq(fileName);
	int objsNum, lightNum;

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
				slineAux >> token;

				Light* light = new Light();

				//position
				float x, y, z;
				sline >> x >> y >> z;
				glm::vec3* pos = new glm::vec3(x, y, z);
				light->setLightPos(pos);

				//la
				sline >> token;
				light->setLa(stof(token));

				//ld
				sline >> token;
				light->setLd(stof(token));

				//ls
				sline >> token;
				light->setLs(stof(token));

				lights.push_back(light);
			}
		}
		else if (temp == "viewport") {
			string token;
			sline >> token;
			width = stoi(token);
			sline >> token;
			height = stoi(token);
		}
	}
}

vector<Obj3D*> ConfigureScene::getObjs()
{
	return objs;
}

vector<Light*> ConfigureScene::getLights()
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

int ConfigureScene::getWidth()
{
	return width;
}

int ConfigureScene::getHeight()
{
	return height;
}
