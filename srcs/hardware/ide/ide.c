#include "hardware/ide/ide.h"
#include "types.h"

void	ide_init()
{
  outl(CONFIG_ADDRESS_FORMAT(,,, 8), CONFIG_ADDRESS);
  inl(CONFIG_DATA);
}
