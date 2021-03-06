#include <iostream>
#include <assert.h>
#include "MemoryController.h"

int main()
{
	auto Controller = Mc_InitContext();
	assert( Controller.CreationStatus == STATUS_SUCCESS );

	uint64_t EProcess = Controller.FindEProcess( 0x4BC );
	assert( EProcess );

	Controller.AttachTo( EProcess );
	printf( "Read Memory: %16llx\n", Controller.ReadVirtual<uint64_t>( ( PVOID ) 0x7ff698b6be14 ) );

	return 0;
}
