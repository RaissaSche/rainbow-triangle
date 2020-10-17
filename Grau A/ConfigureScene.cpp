#include "ConfigureScene.h"
#include "ManageObj.h"
#include <fstream>
#include <sstream>

void ConfigureScene::readFile(string fileName)
{
	ifstream arq(fileName);
	int number;
	int it = 0;

	while (!arq.eof()) {
		string line;
		getline(arq, line);
		stringstream sline;
		sline << line;
		string temp;
		sline >> temp;

		if (it == 0) { //first read
			stringstream stemp;
			stemp << temp;
			number = stoi(temp);

			for (int i = 0; i < number; i++) {

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
				slineAux >> tempAux;
				float tx = stod(tempAux);
				slineAux >> tempAux;
				float ty = stod(tempAux);
				slineAux >> tempAux;
				float tz = stod(tempAux);
				slineAux >> tempAux;
				float s = stod(tempAux);
				slineAux >> tempAux;
				float r = stod(tempAux);

				obj->addInfoTransform(tx, ty, tz, s, r);

				slineAux >> tempAux;
				obj->setErasable(tempAux == "1");

				objs.push_back(obj);
			}
			it++;
		}
		else if (temp == "camera") {
			string token;

			//eye
			cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
			sline >> token;
			cameraPos.x = stoi(token);
			sline >> token;
			cameraPos.y = stoi(token);
			sline >> token;
			cameraPos.z = stoi(token);

			//direction
			cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
			sline >> token;
			cameraTarget.x = stoi(token);
			sline >> token;
			cameraTarget.y = stoi(token);
			sline >> token;
			cameraTarget.z = stoi(token);

			//up
			cameraUp = glm::vec3(0.0f, 0.0f, 0.0f);
			sline >> token;
			cameraUp.x = stoi(token);
			sline >> token;
			cameraUp.y = stoi(token);
			sline >> token;
			cameraUp.z = stoi(token);

		}
		else if (temp == "light") {
			string token;

			//position
			lightPos = glm::vec3(0.0f, 0.0f, 0.0f);
			sline >> token;
			lightPos.x = stoi(token);
			sline >> token;
			lightPos.y = stoi(token);
			sline >> token;
			lightPos.z = stoi(token);

			//la
			sline >> token;
			la = stof(token);
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

glm::vec3 ConfigureScene::getLightPos()
{
	return lightPos;
}

float ConfigureScene::getLa()
{
	return la;
}

int ConfigureScene::getWidth()
{
	return width;
}

int ConfigureScene::getHeight()
{
	return height;
}
