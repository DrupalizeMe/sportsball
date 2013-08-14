<?php
/**
 * @file
 * Import pages from a CSV file.
 */

class SportsBallPageMigration extends SportsBallMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import basic pages from a CSV file.');

    $options = array(
      'header_rows' => 1,
      'delimiter' => '|',
    );
    $this->source = new MigrateSourceCSV('/Users/joe/Sites/demos/migrate-video/sample_data.csv', array(), $options);

    $this->destination = new MigrateDestinationNode('page');

    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'default' => '',
          'description' => 'Title of article.',
        ),
        'date' => array(
          'type' => 'int',
          'length' => 10,
          'unsigned' => TRUE,
          'not null' => TRUE,
          'default' => 0,
          'description' => 'Publication date',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );


    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('created', 'date');
    $this->addFieldMapping('status', 'public');
    $this->addFieldMapping('body', 'copy');



    
  }
}

