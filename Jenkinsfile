pipeline {
  agent none
  stages {
    stage('build') {
      steps {
        echo 'simple pipeline'
      }
    }
    stage('step2') {
      steps {
        isUnix()
        node(label: 'node') {
          isUnix()
        }
        
      }
    }
  }
}