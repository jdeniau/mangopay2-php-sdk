<?php
namespace MangoPay\Tests;

/**
 * Tests basic methods for transfers
 */
class Transfers extends Base {
     
    function test_Transfers_Create() {
        $john = $this->getJohn();
        $transfer = $this->getTransfer();
        
        $this->assertTrue($transfer->Id > 0);
        $this->assertEqual($transfer->AuthorId, $john->Id);
        $this->assertEqual($transfer->CreditedUserId, $john->Id);
    }
    
    function test_Transfers_Get() {
        $john = $this->getJohn();
        $transfer = $this->getTransfer();
        
        $getTransfer = $this->_api->Transfers->Get($transfer->Id);
        
        $this->assertIdentical($transfer->Id, $getTransfer->Id);
        $this->assertEqual($getTransfer->AuthorId, $john->Id);
        $this->assertEqual($getTransfer->CreditedUserId, $john->Id);
        $this->assertIdenticalInputProps($transfer, $getTransfer);
    }
}