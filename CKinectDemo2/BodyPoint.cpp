#include "BodyPoint.h"

BodyPoint::BodyPoint() {

}

BodyPoint::BodyPoint(BodyParts point)
{
	pointRepresented = point;
	cout << "Inicia joint " << point << endl;
	currentPosition.name = point;
	currentPosition.x = 0.0f;
	currentPosition.y = 0.0f;
	currentPosition.z = 0.0f;
}


BodyPoint::~BodyPoint()
{
}

BodyPointPosition BodyPoint::getCurrentPosition() {
	return currentPosition;
}

BodyPointPosition BodyPoint::updatePosition(NUI_SKELETON_DATA & skeleton) {
	int jointIndex = mapPoint(pointRepresented);
	currentPosition.x = skeleton.SkeletonPositions[jointIndex].x;
	currentPosition.y = skeleton.SkeletonPositions[jointIndex].y;
	currentPosition.z = skeleton.SkeletonPositions[jointIndex].z;
	return currentPosition;
}

_NUI_SKELETON_POSITION_INDEX BodyPoint::mapPoint(BodyParts part) {
	switch (part) {
	case HipCenter:
		return NUI_SKELETON_POSITION_HIP_CENTER;
	case Spine:
		return NUI_SKELETON_POSITION_SPINE;
	case ShoulderCenter:
		return NUI_SKELETON_POSITION_SHOULDER_CENTER;
	case Head:
		return NUI_SKELETON_POSITION_HEAD;
	case ShoulderLeft:
		return NUI_SKELETON_POSITION_SHOULDER_LEFT;
	case ElbowLeft:
		return NUI_SKELETON_POSITION_ELBOW_LEFT;
	case WristLeft:
		return NUI_SKELETON_POSITION_WRIST_LEFT;
	case HandLeft:
		return NUI_SKELETON_POSITION_HAND_LEFT;
	case ShoulderRight:
		return NUI_SKELETON_POSITION_SHOULDER_RIGHT;
	case ElbowRight:
		return NUI_SKELETON_POSITION_ELBOW_RIGHT;
	case WristRight:
		return NUI_SKELETON_POSITION_WRIST_RIGHT;
	case HandRight:
		return NUI_SKELETON_POSITION_HAND_RIGHT;
	case HipLeft:
		return NUI_SKELETON_POSITION_HIP_LEFT;
	case KneeLeft:
		return NUI_SKELETON_POSITION_KNEE_LEFT;
	case AnkleLeft:
		return NUI_SKELETON_POSITION_ANKLE_LEFT;
	case FootLeft:
		return NUI_SKELETON_POSITION_FOOT_LEFT;
	case HipRight:
		return NUI_SKELETON_POSITION_HIP_RIGHT;
	case KneeRight:
		return NUI_SKELETON_POSITION_KNEE_RIGHT;
	case AnkleRight:
		return NUI_SKELETON_POSITION_ANKLE_RIGHT;
	case FootRight:
		return NUI_SKELETON_POSITION_FOOT_RIGHT;
	}
}