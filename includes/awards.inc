<?php

class SportsBallAwardsMigration extends SportsBallMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import award names as vocabulary terms.');

    $query = $this->getConnection()->select('awardsplayers', 'a')
      ->fields('a', array('awardID'))
      ->groupBy('a.awardID')
      ->orderBy('a.awardID');
    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationTerm('awards');

    // Create a map for source > dest record mapping.
    $this->map = new MigrateSQLMap(
      // Our map needs a machine name, lets just use the name of the migration.
      $this->machineName,
      // Source unique ID field to use for mapping.
      array(
        'awardID' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'default' => '',
          'description' => 'Award ID/Name',
        ),
      ),
      // Destination, unique ID field to use for mapping.
      MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('name', 'awardID');
  }
}
