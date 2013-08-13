<?php
/**
 * @file
 * Migration for player data.
 */

class SportsBallPlayerMigration extends SportsBallMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import player data from the Lahman database.');

    $query = $this->getConnection()->select('master', 'm')
      ->fields('m', array('playerID', 'nameFirst', 'nameLast'))
      ->isNotNull('m.playerID');

    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationNode('player');

    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'playerID' => array(
          'type' => 'varchar',
          'length' => 10,
          'not null' => TRUE,
          'default' => '',
          'description' => 'Player ID.',
          'alias' => 'm',
         ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('title', 'nameFirst');
  }
}
