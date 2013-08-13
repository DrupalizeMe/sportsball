<?php

abstract class SportsBallMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->team = array(
      new MigrateTeamMember('Addi Berry', 'addi@example.com',
                            t('Product Owner')),
      new MigrateTeamMember('Joe Shindelar', 'joe@example.com',
                            t('Implementor')),
    );
  }

  public function getConnection($connection = 'baseball') {
    return Database::getConnection('default', $connection);
  }
}
