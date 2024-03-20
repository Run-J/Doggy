// fileName: driver.cpp
// project: assignment 3
// programmer: Run Ji 8874457
// first version: 2/08/2024
// description: 
//		-- This program allows the user to control an analog radio through a menu-driven interface that 
//		-- includes operations such as powering on and off, adjusting volume, switching channels, 
//		-- setting and selecting preset stations. This is done until the user chooses to exit the program.

#include "AmFmRadio.h"

// kMenuTogglePower is assigned a value of 1. 
// Each subsequent option (e.g., kMenuSetVolume, kMenuToggleAMFM, etc.) c
// orresponds to a different menu action, and their values are automatically incremented (2, 3...)
enum menuItems
{
	kMenuNothing = 0,	// special constant for initialization only
	kMenuTogglePower = 1, kMenuSetVolume, kMenuToggleAMFM, kMenuSetButton, kMenuSelectButton,
	kMenuShowCurrentSettings, kMenuScanUp, kMenuScanDown, kMenuQuit
};

void test01(void)
{
	freqs preset[NUM_OF_DEFAULT_STATION];
	int amFreq = 540;
	double fmFreq = 90.2;

	for (int i = 0; i < 5; i++)
	{
		preset[i].amFreq = amFreq;
		amFreq = amFreq + 50;
	}
	for (int i = 0; i < 5; i++)
	{
		preset[i].fmFreq = fmFreq;
		fmFreq = fmFreq + 0.8;
	}
	AmFmRadio test(true, preset);
	test.ShowCurrentSettings();
}

int main(void)
{
	//test01();
	int			volumeOK = 0; // volumeOK variable is used to store the return value of the SetVolume method
	int			buttonOK = 0; // volumeOK variable is used to store the return value of the SetPresetButton
	int			buttonNum = 0; // indicates botton index
	menuItems	choice = kMenuNothing; // user choice
	char		buf[INPUT_BUFFER] = { 0 };
	AmFmRadio	jazzy(true); // instantiate a radio called jazzy
	bool		on = false;
	
	do
	{
		printf
		(
			"\n\nMAIN MENU\n"
			"=========\n\n"
			"1.  Toggle Power\n"
			"2.  Set Volume\n"
			"3.  Toggle AM / FM Band\n"
			"4.  Set a Preset Button\n"
			"5.  Select a Preset Button\n"
			"6.  Show Current Settings\n"
			"7.  Scan Up\n"
			"8.  Scan Down\n"
			"9.  Quit the Program\n"
			"\nMake a selection from the menu\n"
		);

		fgets(buf, sizeof(buf), stdin);
		choice = (menuItems) atoi(buf);
		
		switch( choice )
		{
		case kMenuTogglePower:
		{
			jazzy.PowerToggle();
			break;
		}

		case kMenuSetVolume: 
		{
			volumeOK = jazzy.SetVolume();
			if (volumeOK == 0) // 0 means SetVolume return value is 0, that indicates user enters volume less than minimum volume
			{
				printf("\nVolume was set to 0.");
			}
			else if (volumeOK == 2) // Contrary to the above
			{
				printf("\nVolume was set to 100.");
			}
			else if (volumeOK == -1)
			{
				printf("\nThe radio is power off, the volume can not be changed");
			}
			break;
		}

		case kMenuToggleAMFM:
		{
			on = jazzy.IsRadioOn();
			if (on)
			{
				jazzy.ToggleBand();

			}
			else
			{
				printf("\nThe radio must be turned on before the "
					"band can be toggled!");
			}
			break;
		}

		case kMenuSetButton:
		{
			on = jazzy.IsRadioOn();
			if (on) // radio is power on
			{
				printf("\nWhich button do you want to set?");
				fgets(buf, sizeof(buf), stdin);
				buttonNum = atoi(buf) - 1; // because buttonNum as a index, so -1
				buttonOK = jazzy.SetPresetButton(buttonNum);
				if (buttonOK == false)
				{
					printf("\nYou entered an invalid button number!");
				}
			}
			else // radio is power off
			{
				printf("\nYou must turn the radio on before you set the buttons!\n");
			}
			break;
		}

		case kMenuSelectButton:
		{
			on = jazzy.IsRadioOn();
			if (on) // radio on
			{
				printf("\nEnter the number of the preset button: ");
				fgets(buf, sizeof(buf), stdin);
				buttonNum = atoi(buf) - 1; // because buttonNum as a index, so -1
				buttonOK = jazzy.SelectPresetButton(buttonNum);
				if (buttonOK == false)
				{
					printf("\nYou entered an invalid button number!");
				}
			}
			else // radio off
			{
				printf("\nYou must turn the radio on before you set the buttons!\n");
			}
			break;
		}

		case kMenuShowCurrentSettings:
		{
			jazzy.ShowCurrentSettings();
			break;
		}

		case kMenuScanUp:
		{
			on = jazzy.IsRadioOn();
			if (on)
			{
				jazzy.ScanUp();
			}
			else
			{
				printf("\nYou must turn the radio on before you can use the scan up button!\n");
			}
			break;
		}

		case kMenuScanDown:
		{
			on = jazzy.IsRadioOn();
			if ( on )
			{
				jazzy.ScanDown();
			}
			else
			{
				printf("\nYou must turn the radio on before you can use the scan down button!\n");
			}
			break;
		}

		case kMenuQuit:
		{
			printf("\nQuitting the program.\n");
			printf("\nGoodbye!\n");
			return 0;
		}

		default:
		{
			printf("You have entered an invalid selection. Please make \n"
				"another selection.\n");
			break;
		}

		} // end switch

		if( choice != kMenuShowCurrentSettings )
		{ 
			jazzy.ShowCurrentSettings(); // always present the current setting
		}

	}while (choice != kMenuQuit);

	return 0;

}