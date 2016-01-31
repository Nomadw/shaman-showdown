#include "Controls.h"


Controls::Controls(void) // creates the keys pressed and released vectors
{
	keysPressed = vector<WPARAM>();
	keysReleased = vector<WPARAM>();
}


Controls::~Controls(void)
{

}

void Controls::handleKeyPressed(WPARAM keyCode) // checks if the keys is already in the pressed list and if not adds it to it 
{
	if (!isKeyPressed(keyCode))
	{
		keysPressed.push_back(keyCode);
	}
}

void Controls::handleKeyRelease(WPARAM keyCode) // remove the key from the pressed list and add it to the released list
{
	unsigned int i = 0;
	bool found = false;
	while (!found && i < keysPressed.size()) // do a linear search of the pressed list for the key thats been pressed
	{
		if (keysPressed.at(i) == keyCode)
		{
			keysPressed.erase(keysPressed.begin() + i); // when found remove it from the pressed list
			found = true;
		}
		else
		{
			i++;
		}
	}
	keysReleased.push_back(keyCode); // add the key to the released list
}

bool Controls::isKeyReleased(WPARAM keyCode) // returns if the key was found in the keys released list
{
	unsigned int i = 0;
	bool found = false;
	while (i < keysReleased.size() && !found) // performs a linear search of the keys released list for the key
	{
		if (keysReleased.at(i) == keyCode)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	return found; // returns if it was found or not
}

bool Controls::isKeyPressed(WPARAM keyCode) // same implementation as the function above except its on the keys pressed list
{
	UINT nDevices;
	PRAWINPUTDEVICELIST pRawInputDeviceList;
	if (GetRawInputDeviceList(NULL, &nDevices, sizeof(RAWINPUTDEVICELIST)) != 0) {}
	if ((pRawInputDeviceList = reinterpret_cast<PRAWINPUTDEVICELIST>(malloc(sizeof(RAWINPUTDEVICELIST) * nDevices))) == NULL) {}
	if (GetRawInputDeviceList(pRawInputDeviceList, &nDevices, sizeof(RAWINPUTDEVICELIST)) == (sizeof(UINT)) - 1) {}
	// do the job...

	int fuck = sizeof(PRAWINPUTDEVICELIST);

	for (int i = 0; i < nDevices; i++)
	{
		
		auto device = pRawInputDeviceList[i];
		UINT pcbSize;

		if (device.dwType == RIM_TYPEKEYBOARD)
		{
			UINT size;

			LPVOID data = NULL;

			UINT test = GetRawInputDeviceInfo((HRAWINPUT)device.hDevice, RIDI_DEVICEINFO, data, &pcbSize);

			int i = 12;
		}
	}

	// after the job, free the RAWINPUTDEVICELIST
	free(pRawInputDeviceList);

	unsigned int i = 0;
	bool found = false;
	while (i< keysPressed.size() && !found)
	{
		if (keysPressed.at(i) == keyCode)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	return found;
}

void Controls::clearKeysReleased() // empties the keys released list
{
	keysReleased.clear();
}

